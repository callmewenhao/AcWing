#include <iostream>

using namespace std;

const int N = 100010, INF = 1e9+7;

int n, a[N], f[N][3];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // 初始化
    f[0][0] = f[0][1] = -INF;
    f[0][2] = 0;
    // 状态机递推
    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i-1][0], f[i-1][2] - a[i]);
        f[i][1] = f[i-1][0] + a[i];
        f[i][2] = max(f[i-1][1], f[i-1][2]);
    }
    // 状态机出口
    cout << max(f[n][1], f[n][2]);
    return 0;
}






