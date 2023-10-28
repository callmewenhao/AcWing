#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int n, m, w[N], v[N], f[N][N];

int h[N], e[N], ne[N], idx;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int x) {
    for (int i = h[x]; ~i; i = ne[i]) {
        int y = e[i];
        dfs(y);
        // 必选根节点 x 所以预留体积 v[x] 
        for (int j = m - v[x]; j >= 0; j--) {
            // 划分成体积为 0 1 2 ... k ... m-1 m 的这个 m+1 个物品
            // 对应价值是 f[y][k]
            for (int k = 0; k <= j; k++) {  // 物品体积 k 要小于背包体积 j
                f[x][j] = max(f[x][j], f[x][j-k] + f[y][k]);
            }
        }
    }
    // 必选根节点，用这个物品更新 f[x][j]
    for (int j = m; j >= v[x]; j--) 
        f[x][j] = f[x][j-v[x]] + w[x]; // 必选没有 max！
    // 根据题意，无法选根节点的方案价值都是 0
    for (int j = 0; j < v[x]; j++)
        f[x][j] = 0;
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);
    int root = -1;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> v[i] >> w[i] >> p;
        if (p == -1) root = i;
        else add(p, i);
    }

    dfs(root);

    cout << f[root][m];

    return 0;
}













