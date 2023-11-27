#include <iostream>
#include <cstring>

using namespace std;

const int N = 110, M = 2 * N;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int f[N][N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int x, int fa) {
    for (int i = h[x]; ~i; i = ne[i]) {
        int y = e[i];
        if (y == fa) continue;

        dfs(y, x);
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k < j; k++) {
                f[x][j] = max(f[x][j], f[x][j-k-1] + f[y][k] + w[i]);
            }
        }
    }
}

int main() {

    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dfs(1, -1);
    cout << f[1][m];

    return 0;
}












