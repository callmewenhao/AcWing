#include <iostream>
#include <cstring>

using namespace std;

const int N =  1600;

int n, f[N][2];
int h[N], e[N], ne[N], idx;
bool st[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int x) {
    f[x][0] = 0;
    f[x][1] = 1;

    for (int i = h[x]; ~i; i = ne[i]) {
        int y = e[i];
        dfs(y);

        f[x][0] += f[y][1];
        f[x][1] += min(f[y][0], f[y][1]);
    }
}

int main() {
    while (cin >> n) {
        idx = 0;
        memset(h, -1, sizeof h);
        memset(st, 0, sizeof st);
        for (int i = 0; i < n; i++) {
            int x, m;
            scanf("%d:(%d)", &x, &m);
            for (int i = 0; i < m; i++) {
                int y;
                cin >> y;
                add(x, y);
                st[y] = true;
            }
        }

        int root = 0;
        while (st[root]) root++;

        dfs(root);
        cout << min(f[root][0], f[root][1]) << endl;
    }
    return 0;
}




