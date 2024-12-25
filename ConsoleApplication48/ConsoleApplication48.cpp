#include <iostream>
using namespace std;

// Метод Крамера
double determinant(double a, double b, double c, double d) {
    return a * d - b * c;
}

void solveSystem(double a1, double b1, double c1, double d1,
                 double a2, double b2, double c2, double d2) {
    double D = determinant(a1, b1, a2, b2);
    if (D == 0) {
        cout << "Система не имеет единственного решения." << endl;
        return;
    }
    double Dx = determinant(c1, b1, c2, b2);
    double Dy = determinant(a1, c1, a2, c2);
    double x = Dx / D;
    double y = Dy / D;
    cout << "Решение системы:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

// Метод Гаусса 
void gaussianElimination(double a[3][4]) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = 0; k < 4; k++) {
                a[j][k] -= ratio * a[i][k];  // Исправлено
            }
        }
    }

    double x[3];
    x[2] = a[2][3] / a[2][2];
    for (int i = 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < 3; j++) {
            sum += a[i][j] * x[j];  // Исправлено
        }
        x[i] = (a[i][3] - sum) / a[i][i];
    }

    cout << "Решение системы:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

const int MAX_NODES = 100; // Максимальное количество узлов

int main() {
    setlocale(LC_ALL, "rus");

    // Метод Крамера
    double a1 = 2, b1 = 1, c1 = 5, d1 = 0; 
    double a2 = 1, b2 = -1, c2 = 1, d2 = 0; 
    solveSystem(a1, b1, c1, d1, a2, b2, c2, d2);

    // Метод Гаусса
    double a[3][4] = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };
    gaussianElimination(a);
}
