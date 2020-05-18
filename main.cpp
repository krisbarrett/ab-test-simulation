
#include <cstdio>
#include <thread>
#include "ab_test.h"

using namespace std;

int diffs = 0;

void run(int i, int sims) {
    printf("starting thread %u\n", i);

    for(int i = 0; i < sims; i++) {
        ABTest ab = ABTest(0.02, 0.02*1.08);
        int n = 121589;

        for(int j = 0; j < n; j++) {
            ab.playA();
            ab.playB();
        }

        if(ab.pValue() < 0.05) {
            diffs++;
        }
    }
}

int main() {
    unsigned int numThreads = thread::hardware_concurrency();
    int simsPerThread = 10000 / numThreads;

    thread threads[numThreads];

    for(int i = 0; i < numThreads; i++) {
        threads[i] = thread(run, i, simsPerThread);
    }
    for(int i = 0; i < numThreads; i++) {
        threads[i].join();
    }


    printf("%.2f%%\n", double(diffs) / 100.0);

    return 0;
}
