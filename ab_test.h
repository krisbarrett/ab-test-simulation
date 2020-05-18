//
// Created by krisb on 5/17/20.
//

#ifndef SPLITTEST_AB_TEST_H
#define SPLITTEST_AB_TEST_H

class ABTest {
    double pa, pb;
    int ca, cb, na, nb;
public:
    ABTest( double, double);
    void playA();
    void playB();
    double pValue();
protected:
    int play(double);
};

#endif //SPLITTEST_AB_TEST_H
