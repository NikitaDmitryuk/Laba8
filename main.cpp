#include <QCoreApplication>
#include "math.h"
#include <iostream>
#include "fstream"
#include "point.h"
#include "diffeq.h"

using namespace std;

double f(double x, double u){
    return 2.0 * (pow(x, 4) + u) / x;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ofstream fout;
    fout.open("result.txt", ios::trunc);
    fout.close();

    enum Method{
        EULER
    };

    double h = 0.001;
    DiffEq eq = DiffEq(h);
    vector<Point> U;

    U = eq(f, 2.0, 1.0, 3.0, EULER); // eq(функция, u(l1), l1, l2)

    fout.open("result.txt", ios::app);
    for(auto u : U){
        fout << u.getX() << "\t" << u.getY() << endl;
    }
    fout.close();

    string command2 = "python3 main.py";
    cout << command2 << endl;
    const char *com2 = command2.c_str();
    system(com2);

    cout << "Успешное выполнение программы!..." << endl;

    return a.exec();
}
