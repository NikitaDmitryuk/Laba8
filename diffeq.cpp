#include "diffeq.h"

DiffEq::DiffEq(double _h)
{
    h = _h;
}

vector<Point> DiffEq::operator()(Func2 func, double ul1, double l1, double l2, int method){
    vector<Point> point;
    point.push_back(Point(l1, ul1));
    double k0, k1, k2, k3;

    switch (method) {
    case EULER:

        for(double x = l1 + h; x <= l2; x += h){
            point.push_back(Point(x, point.back().getY() + h * func(x, point.back().getY())));
        }
        break;

    case MOD_EULER:
        for(double x = l1 + h; x <= l2; x += h){
            point.push_back(Point(x, point.back().getY() + h / 2.0 * ( func(x, point.back().getY()) + func(x + h, point.back().getY() + h * func(x, point.back().getY())) )));
        }
        break;

    case IMPR_EULER:
        for(double x = l1 + h; x <= l2; x += h){
            point.push_back(Point(x, point.back().getY() + h * func(x + h / 2.0, point.back().getY() + h / 2.0 * func(x, point.back().getY()))));
        }
        break;

    case RUNGE_KUTTA:
        for(double x = l1 + h; x <= l2; x += h){
            k0 = func(x, point.back().getY());
            k1 = func(x + h / 2.0, point.back().getY() + h * k0 / 2.0);
            k2 = func(x + h / 2.0, point.back().getY() + h * k1 / 2.0);
            k3 = func(x + h, point.back().getY() + h * k2);
            point.push_back(Point(x, point.back().getY() + h / 6.0 * (k0 + 2.0 * k1 + 2.0 * k2 + k3)));
        }
        break;
    }

    return point;
}

vector<Point> DiffEq::operator()(Func2 func, double ul1, double dul1, double l1, double l2, int method){
    vector<Point> point;
    vector<Point> diff;
    point.push_back(Point(l1, ul1));
    diff.push_back(Point(dul1));
    double diffOld, yOld;

    switch (method) {
    case EULER:

        for(double x = l1 + h; x <= l2; x += h){
            diffOld = diff.back().getX();
            yOld = point.back().getY();
            double f = func(yOld, diffOld);
            diff.push_back(Point(diffOld + h * func(yOld, diffOld)));
            point.push_back(Point(x, yOld + h * diffOld));

        }
        break;
    }

    return point;
}
