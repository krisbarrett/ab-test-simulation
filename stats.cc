//
// Created by krisb on 5/17/20.
//

#include <cmath>

double PropTest(double control_conversions, double control_views, double variation_conversions, double variation_views) {
    double a = control_views - control_conversions;
    double b = variation_views - variation_conversions;
    double c = control_conversions;
    double d = variation_conversions;
    double n = a + b + c + d;

    if(n == 0) {
        return -1;
    }

    double xa = (a + b) * (a + c) / n;
    double xb = (a + b) * (b + d) / n;
    double xc = (a + c) * (c + d) / n;
    double xd = (b + d) * (c + d) / n;

    if(xa == 0 || xb == 0 || xc == 0 || xd == 0) {
        return -1;
    }

    double q1 = std::pow(a - xa, 2) / xa;
    double q2 = std::pow(b - xb, 2) / xb;
    double q3 = std::pow(c - xc, 2) / xc;
    double q4 = std::pow(d - xd, 2) / xd;

    double chi_sqr = q1 + q2 + q3 + q4;

    return 1 - std::erf(std::sqrt(chi_sqr / 2.0));
}