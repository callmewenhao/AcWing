#include <iostream>

using namespace std;

const int N = 30;

int n, w[N], f[N][N], g[N][N];

void dfs(int l, int r) {
    if (l > r) return;
    cout << g[l][r] << " ";
    dfs(l, g[l][r]-1);
    dfs(g[l][r]+1, r);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (i == j) {
                f[i][j] = w[i];
                g[i][j] = i;
            } else {
                int score = 0;
                for (int k = i; k <= j; k++) {
                    int left = k == i ? 1 : f[i][k-1];
                    int right = k == j ? 1 : f[k+1][j];
                    int score = w[k] + left * right;

                    if (f[i][j] < score) {
                        f[i][j] = score;
                        g[i][j] = k;
                    }
                }
            }
        }
    }

    cout << f[1][n] << endl;
    dfs(1, n);

    return 0;
}












