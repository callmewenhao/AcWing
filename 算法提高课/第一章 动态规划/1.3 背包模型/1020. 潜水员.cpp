#include <iostream>
#include <cstring>

using namespace std;

const int M = 22, N = 80;

int m, n, k, f[M][N];

int main () {

    cin >> m >> n;
    cin >> k;

    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = m; j >= 0; j--) {
            for (int k = n; k >= 0; k--) {
                f[j][k] = min(f[j][k], f[max(0, j-a)][max(0, k-b)] + c);
            }
        }
    }

    cout << f[m][n];

    return 0;
}