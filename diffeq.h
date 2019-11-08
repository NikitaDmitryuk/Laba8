#ifndef DIFFEQ_H
#define DIFFEQ_H
#include "vector"
#include "point.h"

typedef double (*Func2)(double xn, double un);
using namespace std;

class DiffEq
{
public:
    DiffEq(double _h);
    vector<Point> operator()(Func2 func, double ul1, double l1, double l2, int method);
    vector<Point> operator()(Func2 func, double ul1, double dul1, double l1, double l2, int method);

private:
    double h;
    enum Method{
        EULER,
        MOD_EULER,
        IMPR_EULER,
        RUNGE_KUTTA
    };
};

#endif // DIFFEQ_H
