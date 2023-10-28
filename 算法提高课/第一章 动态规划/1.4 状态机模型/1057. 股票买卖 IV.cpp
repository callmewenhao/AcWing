#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 110;

int n, m, a[N];
int f[N][M][2];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 初始化
    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= n; i++) f[i][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1] + a[i]);
            f[i][j][1] = max(f[i-1][j][1], f[i-1][j-1][0] - a[i]);
        }
    }

    int res = 0;
    for (int j = 1; j <= m; j++) {
        res = max(res, f[n][j][0]);
    }

    cout << res;

    return 0;
}





