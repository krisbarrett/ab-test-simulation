//
// Created by krisb on 5/17/20.
//

#ifndef SPLITTEST_AB_TEST_H
#define SPLITTEST_AB_TEST_H

class ABTest {
    double pa, pb;
    int ca, cb, na, nb, n;
public:
    ABTest( double, double, int);
    bool next();
    double pValue();
protected:
    void playA();
    void playB();
    int play(double);
    double random();
};

#endif //SPLITTEST_AB_TEST_H
