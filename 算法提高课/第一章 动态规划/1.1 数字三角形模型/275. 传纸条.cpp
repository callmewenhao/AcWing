#include <iostream>

using namespace std;

const int N = 55;

int n, m, a[N][N], f[2*N][N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int k = 2; k <= n+m; k++) {
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if (0 < j1 && 0 < j2 && j1 <= m && j2 <= m) {
                    int& x = f[k][i1][i2];
                    int t = a[i1][j1];
                    if (i1 != i2) t += a[i2][j2];

                    x = max(x, f[k-1][i1-1][i2-1] + t);
                    x = max(x, f[k-1][i1-1][i2] + t);
                    x = max(x, f[k-1][i1][i2-1] + t);
                    x = max(x, f[k-1][i1][i2] + t);
                }
            }
        }
    }

    cout << f[n+m][n][n];

    return 0;
}