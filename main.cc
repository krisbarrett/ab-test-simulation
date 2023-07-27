
#include <cstdio>
#include <thread>
#include "ab_test.h"

using namespace std;

int diffs = 0;

void runSimulation(int i, int sims, double a, double b, int requiredN) {
    for(int i = 0; i < sims; i++) {
        ABTest ab = ABTest(a, b, requiredN);

        while (ab.next()) {}

        if(ab.pValue() < 0.05) {
            diffs++;
        }
    }
}

void runSimulations(string label, int totalSims, double a, double b, int requiredN) {
    diffs = 0;
    int numThreads = thread::hardware_concurrency();
    thread threads[numThreads];
    int simsPerThread = totalSims / thread::hardware_concurrency();

    for(int i = 0; i < numThreads; i++) {
        threads[i] = thread(runSimulation, i, simsPerThread, a, b, requiredN);
    }
    for(int i = 0; i < numThreads; i++) {
        threads[i].join();
    }
    printf("%s: %.2f%%\n", label.c_str(), 100.0 *double(diffs) / double(numThreads*simsPerThread));
}

int main() {
    int totalSims = 10000;
    double mde = 0.05;
    double a = 0.2;
    double b = a * (1+mde);
    int requiredN = 25580;

    runSimulations("false positive rate", totalSims, a, a, requiredN);
    runSimulations("true positive rate", totalSims, a, b, requiredN);

    return 0;
}
