#include "diffeq.h"

DiffEq::DiffEq(double _h)
{
    h = _h;
}

vector<Point> DiffEq::operator()(Func func, double ul1, double l1, double l2, int method){
    vector<Point> point;
    switch (method) {
    case EULER:
        point.push_back(Point(l1, ul1));
        for(double x = l1 + h; x <= l2; x += h){
            point.push_back(Point(x, point.back().getY() + h * func(x, point.back().getY())));
        }
        break;
    }

    return point;
}
