#include <iostream>

using namespace std;

const int N = 410, INF = 1e9+7;

int n, a[N], s[N], fmn[N][N], fmx[N][N];

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for (int i = 1; i <= 2*n; i++) {
        s[i] = s[i-1] + a[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= 2*n; i++) {
            int j = i + len - 1;

            fmn[i][j] = INF, fmx[i][j] = -INF;
            for (int k = i; k < j; k++) {
                fmn[i][j] = min(fmn[i][j], fmn[i][k] + fmn[k+1][j] + s[j] - s[i-1]);
                fmx[i][j] = max(fmx[i][j], fmx[i][k] + fmx[k+1][j] + s[j] - s[i-1]);
            }
        }
    }

    int mn = INF, mx = -INF;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, fmn[i][i+n-1]);
        mx = max(mx, fmx[i][i+n-1]);
    }

    cout << mn << endl << mx;

    return 0;
}




