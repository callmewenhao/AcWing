#include <iostream>
#include <cstring>

using namespace std;

const int N = 10010, M = 2 * N;

int n, ans;
int h[N], e[M], w[M], ne[M], idx;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int x, int fa) {
    int dist = 0;
    int d1 = 0, d2 = 0;

    for (int i = h[x]; ~i; i = ne[i]) {
        int y = e[i];
        if (y == fa) continue;

        int d = dfs(y, x) + w[i];
        dist = max(dist, d);
        if (d >= d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;
    }
    ans = max(ans, d1 + d2);
    return dist;
}

int main() {

    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dfs(1, -1);
    cout << ans;

    return 0;
}














