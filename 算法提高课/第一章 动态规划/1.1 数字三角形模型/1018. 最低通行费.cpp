#include <iostream>

using namespace std;

const int N = 110, INF = 1e9+7;

int n, a[N][N], f[N][N];

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = INF;
            if (i == 1 && j == 1) f[i][j] = a[i][j];
            else {
                if (i > 1) f[i][j] = min(f[i][j], f[i-1][j] + a[i][j]);
                if (j > 1) f[i][j] = min(f[i][j], f[i][j-1] + a[i][j]);
            }
        }
    }
    
    cout << f[n][n];

    return 0;
}
