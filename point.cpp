#include "point.h"

Point::Point(double _x, double _y)
{
    x = _x;
    y = _y;
}

Point::Point()
{

}

double Point::getX(){
    return x;
}

double Point::getY(){
    return y;
}

void Point::setX(double _x){
    x = _x;
}

void Point::setY(double _y){
    y = _y;
}
