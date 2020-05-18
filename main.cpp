
#include <cstdio>
#include <thread>
#include "ab_test.h"

using namespace std;

int diffs = 0;

void run(int i, int sims) {
    printf("starting thread %u\n", i);

    for(int i = 0; i < sims; i++) {
        ABTest ab = ABTest(0.02, 0.02, 121589);

        while (ab.next()) {}

        if(ab.pValue() < 0.05) {
            diffs++;
        }
    }
}

int main() {
    unsigned int numThreads = thread::hardware_concurrency();
    int totalSims = 10000;
    int simsPerThread = totalSims / numThreads;

    thread threads[numThreads];

    for(int i = 0; i < numThreads; i++) {
        threads[i] = thread(run, i, simsPerThread);
    }
    for(int i = 0; i < numThreads; i++) {
        threads[i].join();
    }


    printf("%.2f%%\n", 100.0 *double(diffs) / double(numThreads*simsPerThread));

    return 0;
}
