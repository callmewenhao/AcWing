#include <iostream>

using namespace std;
using LL = long long;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        // 对应的位置为 1
        if (k & 1)
            res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;  // 平方一下
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    int a, p;
    while (n--) {
        cin >> a >> p;
        int res = qmi(a, p - 2, p);

        // 要先判断是否有逆元
        if (a % p)
            cout << res << endl;
        else
            cout << "impossible" << endl;
    }
    return 0;
}
