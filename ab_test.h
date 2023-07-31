//
// Created by krisb on 5/17/20.
//

#ifndef SPLITTEST_AB_TEST_H
#define SPLITTEST_AB_TEST_H

class ABTest {
    double pa, pb; // probabilities for A and B
    int ca, cb;    // successes for A and B
    int na, nb;    // number of trials for A and B
    int n;         // required sample size
public:
    /*
     * Initializes a new ABTest with the probability a, the probability of b, and the required sample size
     * */
    ABTest(double a, double b, int requiredN);

    /*
     * Randomly picks A or B and calls trialA() or trialB() and returns true if the ABTest should continue running.
     */
    bool next();

    /*
     * Runs a test of equal proportions and returns the resulting p-value.
     */
    double pValue();
protected:
    /*
     * Runs a trial for A and updates the successes and number of trials.
     */
    void trialA();

    /*
     * Runs a trial for B and updates the successes and number of trials
     */
    void trialB();

    /*
     * Runs a Bernoulli trial with probability p, returning 1 for a success and 0 for a failure.
     */
    int trial(double p);

    /*
     * Returns a random number between 0 and 1.
     */
    double random();
};

#endif //SPLITTEST_AB_TEST_H
