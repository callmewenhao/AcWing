/**
 * 计算 卡特兰数
*/

#include <iostream>

using namespace std;

using LL = long long;

const int mod = 1e9+7;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL) res * a % p;
        a = (LL) a * a % p;
        k >>= 1;
    }
    return res;
}

int main() {
    
    int n;
    cin >> n;
    
    // 算组合数
    int res = 1;
    for (int i = n, j = 2 * n; i > 0; i--, j--) {
        // 分子
        res = (LL) res * j % mod;
        // 分母
        res = (LL) res * qmi(i, mod - 2, mod) % mod;
    }
    
    // n+1 逆元
    res = (LL) res * qmi(n + 1, mod - 2, mod) % mod;
    
    cout << res << endl;
    
    return 0;
}