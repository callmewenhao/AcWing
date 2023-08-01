#include <iostream>

using namespace std;
using LL = long long;

const int mod = 1e9+7;

// 快速幂
int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    // 计算卡特兰数 C_2n^n / (n+1)
    int res = 1;
    // 先算分子，组合数
    int a = 2*n, b = n;
    for (int i = a; i > a - b; i--) res = (LL)res * i % mod;
    for (int i = b; i > 0; i--) res = (LL)res * qmi(i, mod - 2, mod) % mod;
    // 分母逆元
    res = (LL)res * qmi(n+1, mod - 2, mod) % mod;

    // 输出卡特兰数
    cout << res << endl;

    return 0;
}
























