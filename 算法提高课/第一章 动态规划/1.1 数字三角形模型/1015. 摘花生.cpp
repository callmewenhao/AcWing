#include <iostream>

using namespace std;

const int N = 110;

int t;

int n, m, a[N][N];

int f[N][N];

int main() {
    
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = max(f[i-1][j], f[i][j-1]) + a[i][j];
            }
        }
        cout << f[n][m] << endl;
    }
    
    return 0;
}