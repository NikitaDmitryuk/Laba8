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
    fout.open("EULER.txt", ios::trunc);
    fout.close();
    fout.open("MOD_EULER.txt", ios::trunc);
    fout.close();
    fout.open("IMPR_EULER.txt", ios::trunc);
    fout.close();
    fout.open("RUNGE_KUTTA.txt", ios::trunc);
    fout.close();

    enum Method{
        EULER,
        MOD_EULER,
        IMPR_EULER,
        RUNGE_KUTTA
    };

    double h = 0.05;
    DiffEq eq = DiffEq(h);
    vector<Point> U;

    U = eq(f, 2.0, 1.0, 3.0, EULER); // eq(функция, u(l1) - начальное условие в точке l1, l1, l2 - область решения)
    fout.open("EULER.txt", ios::app);
    for(auto u : U){
        fout << u.getX() << "\t" << u.getY() << endl;
    }
    fout.close();


    U = eq(f, 2.0, 1.0, 3.0, MOD_EULER);
    fout.open("MOD_EULER.txt", ios::app);
    for(auto u : U){
        fout << u.getX() << "\t" << u.getY() << endl;
    }
    fout.close();

    U = eq(f, 2.0, 1.0, 3.0, IMPR_EULER);
    fout.open("IMPR_EULER.txt", ios::app);
    for(auto u : U){
        fout << u.getX() << "\t" << u.getY() << endl;
    }
    fout.close();

    U = eq(f, 2.0, 1.0, 3.0, RUNGE_KUTTA);
    fout.open("RUNGE_KUTTA.txt", ios::app);
    for(auto u : U){
        fout << u.getX() << "\t" << u.getY() << endl;
    }
    fout.close();


    string command2 = "python3 main.py";
    cout << command2 << endl;
    const char *com2 = command2.c_str();
    if(system(com2) == 0)
        cout << "Успешное выполнение программы!..." << endl;
    else
        cout << "ОШИБКА!!!" << endl;

    return a.exec();
}
