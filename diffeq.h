#ifndef DIFFEQ_H
#define DIFFEQ_H
#include "vector"
#include "point.h"

typedef double (*Func)(double xn, double un);
using namespace std;

class DiffEq
{
public:
    DiffEq(double _h);
    vector<Point> operator()(Func func, double uL1, double l1, double l2, int method);
private:
    double h;
    enum Method{
        EULER
    };
};

#endif // DIFFEQ_H
