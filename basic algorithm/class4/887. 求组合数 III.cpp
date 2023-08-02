/**
 * Lucas 定理
*/
#include <iostream>

using namespace std;

using LL = long long;

int n, p;
LL a, b;

// 计算快速幂
int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL) res * a % p;
        a = (LL) a * a % p;
        k >>= 1;
    }
    return res;
}

// 单次求组合数
int C(int a, int b, int p) {
    if (b > a) return 0;
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = (LL) res * j % p;
        res = (LL) res * qmi(i, p - 2, p) % p;
    }
    return res;
}

// 定理实现
int lucas(LL a, LL b, int p) {
    // 在 p 范围内的 单次求组合数
    if (a < p && b < p) return C(a, b, p);
    // 不在 p 范围内的 递归计算
    return (LL) C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main() {
    cin >> n;
    while (n--) {
       cin >> a >> b >> p;
       cout << lucas(a, b, p) << endl;
    }
    
    return 0;
}

