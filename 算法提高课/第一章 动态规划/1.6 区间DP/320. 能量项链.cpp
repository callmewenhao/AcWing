#include <iostream>

using namespace std;

const int N = 210;

int n, a[N], f[N][N];

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    
    // 最小长度应该是 3
    for (int len = 3; len <= n+1; len++) {  // 长度应该是 n+1
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1;
            // 最小值保持 0 即可，能量值不会为负数
            for (int k = i + 1; k < j; k++) {
                f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, f[i][i+n]);
    }

    cout << res;

    return 0;
}








