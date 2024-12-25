#include <iostream>
using namespace std;

// Метод Крамера
double crammer(double a, double b, double c, double d) {
    return a * d - b * c;
}

void solveSystem(double a1, double b1, double c1, double d1,
    double a2, double b2, double c2, double d2) {
    double D = crammer(a1, b1, a2, b2);
    if (D == 0) {
        cout << "Система не имеет единственного решения." << endl;
        return;
    }
    double Dx = crammer(c1, b1, c2, b2);
    double Dy = crammer(a1, c1, a2, c2);
    double x = Dx / D;
    double y = Dy / D;
    cout << "Решение системы:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}


int main() {
    setlocale(LC_ALL, "rus");

    // Метод Крамера
    double a1 = 2, b1 = 1, c1 = 77, d1 = 3;
    double a2 = 1, b2 = -1, c2 = 1, d2 = 0;
    solveSystem(a1, b1, c1, d1, a2, b2, c2, d2);
    return 0;
}