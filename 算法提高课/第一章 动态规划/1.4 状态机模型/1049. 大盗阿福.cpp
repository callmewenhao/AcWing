#include <iostream>

using namespace std;

const int N = 1e5+7, INF = 1e9+7;

int t, n;
int a[N], f[N][2];

int main() {

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        f[0][0] = 0, f[0][1] = -INF;
        for (int i = 1; i <= n; i++) {
            f[i][0] = max(f[i-1][0], f[i-1][1]);
            f[i][1] = f[i-1][0] + a[i];
        }

        cout << max(f[n][0], f[n][1]) << endl;
    }

    return 0;
}




