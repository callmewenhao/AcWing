/*
@File    : 4443.cpp
@Author  : wenhao
@Time    : 2023/6/29 10:13
@LC      : 
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        int R, A, B;
        scanf("%d %d %d", &R, &A, &B);
        double area = M_PI * R * R;
        while (R) {
            area +=  M_PI * (A * R) * (A * R);
            R = R * A / B;
            area += M_PI * R * R;
        }
        printf("Case #%d: %lf\n", cases, area);
    }
    return 0;
}