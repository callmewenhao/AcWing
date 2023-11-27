#include <iostream>
#include <cstring>

using namespace std;

const int N = 1510;

int n, f[N][3];
int h[N], e[N], w[N], ne[N], idx;
bool st[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int x) {
    f[x][2] = w[x];

    for (int i = h[x]; ~i; i = ne[i]) {
        int y = e[i];
        dfs(y);

        f[x][0] += min(f[y][1], f[y][2]);
        f[x][2] += min(f[y][0], min(f[y][1], f[y][2]));
    }

    f[x][1] = 1e9;
    for (int i = h[x]; ~i; i = ne[i]) {
        int y = e[i];
        f[x][1] = min(f[x][1], f[y][2] + f[x][0] - min(f[y][1], f[y][2]));
    }
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= n; i++) {
        int x, c, m;
        cin >> x >> c >> m;
        w[x] = c;

        for (int j = 0; j < m; j++) {
            int y;
            cin >> y;
            add(x, y);
            st[y] = true;
        }
    }

    int root = 1;
    while (st[root]) root++;

    dfs(root);
    cout << min(f[root][1], f[root][2]);

    return 0;
}





