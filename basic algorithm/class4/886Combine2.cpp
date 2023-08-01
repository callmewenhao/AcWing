#include <iostream>

using namespace std;
using LL = long long;

const int N = 1e5+7, mod = 1e9+7;

int fact[N], infact[N];

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) {
            res = (LL)res * a % p;
        }
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}


int main() {
    // 预处理阶乘和阶乘逆元
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (LL)fact[i-1] * i % mod;
        infact[i] = (LL)infact[i-1] * qmi(i, mod-2, mod) % mod;
    }

    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << (LL)fact[a] * infact[b] % mod * infact[a - b] % mod << endl;
    }

    return 0;
}