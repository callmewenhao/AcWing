#include <iostream>

using namespace std;

const int N = 11;

int n, a[N][N], f[2*N][N][N];

int main() {

    cin >> n;

    int x, y, z;
    while (cin >> x >> y >> z, x || y || z) {
        a[x][y] = z;
    }

    for (int k = 2; k <= 2*n; k++) {
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if (0 < j1 && 0 < j2 && j1 <= n && j2 <= n) {
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

    cout << f[2*n][n][n];

    return 0;
}










