#include <iostream>
#include <cstring>

using namespace std;

const int N = 10010, M = 2 * N, INF = 0x3f3f3f3f;

int n;
int h[N], e[M], w[M], ne[M], idx;
int d1[N], d2[N], d3[N], p1[N], up[N];
bool is_leaf[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs_down(int x, int fa) {
    d1[x] = d2[x] = -INF;
    for (int i = h[x]; ~i; i = ne[i]) {
        int y = e[i];
        if (y == fa) continue;
        int d = dfs_down(y, x) + w[i];

        if (d >= d1[x]) {
            d2[x] = d1[x];
            d1[x] = d;
            p1[x] = y;
        } else if (d > d2[x]) {
            d2[x] = d;
        }
    }
    if (d1[x] == -INF) {
        d1[x] = d2[x] = 0;
        is_leaf[x] = true;
    }
    return d1[x];
}

void dfs_up(int x, int fa) {
    for (int i = h[x]; ~i; i = ne[i]) {
        int y = e[i];
        if (y == fa) continue;
        
        if (y == p1[x]) up[y] = max(d2[x], up[x]) + w[i];
        else up[y] = max(d1[x], up[x]) + w[i];
        dfs_up(y, x);
    }
}

int main() {

    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dfs_down(1, -1);
    dfs_up(1, -1);

    int ans = d1[1];
    for (int i = 1; i <= n; i++) {
        if (is_leaf[i]) ans = min(ans, up[i]);
        else ans = min(ans, max(d1[i], up[i]));
    }
    cout << ans;

    return 0;
}























