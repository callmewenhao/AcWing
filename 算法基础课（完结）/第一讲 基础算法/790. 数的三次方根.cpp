/*
数的三次方具有二分性
*/
#include <iostream>
using namespace std;
const double prec = 1e-8;
int main() {
    double n;
    cin >> n;
    double l = -100., r = 100.;
    while (r - l > prec) {
        double mid = (r + l) / 2;
        if (mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%.6lf", l);
    return 0;
}


