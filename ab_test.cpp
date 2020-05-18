//
// Created by krisb on 5/17/20.
//

#include "ab_test.h"
#include "stats.h"
#include <random>
#include <thread>
#include <chrono>

using namespace std;

ABTest::ABTest(double a, double b, int requiredN) {
    pa = a;
    pb = b;
    ca = 0;
    cb = 0;
    na = 0;
    nb = 0;
    n = requiredN;
}

bool ABTest::next() {
    if(random() < 0.5) {
        playA();
    } else {
        playB();
    }

    return na < n || nb < n;
}

double ABTest::random() {
    static thread_local mt19937* generator = nullptr;
    if (!generator) {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        generator = new mt19937(seed);
    }
    uniform_real_distribution<double> distribution(0, 1);
    return distribution(*generator);
}

int ABTest::play(double p) {
    return random() <= p ? 1 : 0;
}

void ABTest::playA() {
    ca += play(pa);
    na++;
}

void ABTest::playB() {
    cb += play(pb);
    nb++;
}

double ABTest::pValue() {
    return PropTest(ca, na, cb, nb);
}

