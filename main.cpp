#include <QCoreApplication>
#include "math.h"
#include <iostream>
#include "fstream"
#include "point.h"
#include "diffeq.h"
#include <sstream>

using namespace std;

double f(double x, double u){
    return 2.0 * (pow(x, 4) + u) / x;
}

double f2(double x, double dxdt){
    return -x - 0.2 * dxdt;
}

double fZadacha(double t){
    return exp(-0.1 * t) * (cos(sqrt(0.99) * t) + 0.1 / sqrt(0.99) * sin(sqrt(0.99) * t));
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
    fout.open("ZADACHA1.txt", ios::trunc);
    fout.close();
    fout.open("ZADACHA2.txt", ios::trunc);
    fout.close();
    fout.open("F0.txt", ios::trunc);
    fout.close();
    fout.open("Fdelta1.txt", ios::trunc);
    fout.close();
    fout.open("Fdelta2.txt", ios::trunc);
    fout.close();


    enum Method{
        EULER,
        MOD_EULER,
        IMPR_EULER,
        RUNGE_KUTTA,
        EULER_KROMER
    };

    double h = 0.5;
    if(argv[1] != ""){
        std::stringstream ss;
        ss << argv[1];
        ss >> h;
    }

    cout << "h = " << h << endl;
    double T = 2 * M_PI / sqrt(0.99);
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

    // ЗАДАЧА

    U = eq(f2, 1, 0, 0, T, EULER);
    fout.open("ZADACHA1.txt", ios::app);
    for(auto u : U){
        fout << u.getX() << "\t" << u.getY() << endl;
    }
    fout.close();

    fout.open("Fdelta1.txt", ios::app);
    for(auto u : U){
        fout << u.getX() << "\t" << fZadacha(u.getX()) - u.getY() << endl;
    }
    fout.close();

    U = eq(f2, 1, 0, 0, T, EULER_KROMER);
    fout.open("ZADACHA2.txt", ios::app);
    for(auto u : U){
        fout << u.getX() << "\t" << u.getY() << endl;
    }
    fout.close();


    fout.open("Fdelta2.txt", ios::app);
    for(auto u : U){
        fout << u.getX() << "\t" << fZadacha(u.getX()) - u.getY() << endl;
    }
    fout.close();


    fout.open("F0.txt", ios::app);
    for(double x = 0; x <= T; x += 0.0001){
        fout << x << "\t" << fZadacha(x) << endl;
    }
    fout.close();


    string command2 = "python3 main.py ";
    command2 += to_string(h);
    cout << command2 << endl;
    const char *com2 = command2.c_str();
    if(system(com2) == 0)
        cout << "Успешное выполнение программы!..." << endl;
    else
        cout << "ОШИБКА!!!" << endl;

    string command1 = "python3 zadacha.py ";
    command1 += to_string(h);
    cout << command1 << endl;
    const char *com1 = command1.c_str();
    if(system(com1) == 0)
        cout << "Успешное выполнение программы!..." << endl;
    else
        cout << "ОШИБКА!!!" << endl;

    return a.exec();
}
