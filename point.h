#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point();
    Point(double _x);
    Point(double _x, double _y);
    double getX();
    double getY();
    void setX(double _x);
    void setY(double _y);
private:
    double x, y;
};

#endif // POINT_H
