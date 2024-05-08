#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
using namespace std;

double f(double x) {
    return pow(x - 2, 9);
}

void bisection(double a, double b, double tol) {
    int iterations = 0;
    double c = 0.0;

    while ((b-a)/2 > tol) {
        c = (a+b)/2;
        iterations++;

        if (f(c) == 0.0) {
            break;
        } else if (f(c)*f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    cout << "Root: " << fixed << setprecision(10) << c << endl;
    cout << "Iterations: " << iterations << endl;
    double n = log2((b - a) / (tol));
     cout << "Erro: " << fixed << setprecision(10) << c-n << endl;
}

int main() {
    double a = 0.0;
    double b = 20.0;
    double tol = 1e-10;

    bisection(a, b, tol);

    return 0;
}
