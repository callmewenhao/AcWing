/**
 * 二分图
 * 
 * 染色法判断二分图 
 * 使用的性质：一个图是二分图 当且仅当图当中不含有奇数环
 * 由于不含奇数环，染色过程中不会出现矛盾
 * 
 * 使用深搜或者宽搜进行染色
 * 
 * 时间复杂度 O(n+m)
 * 
*/
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 7, M = 2 * N;

int n, m, color[N];
int h[N], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// 深搜判断能否二分图
bool dfs(int u, int c) {
    color[u] = c;  // 染色
    // dfs 染色子节点
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (color[j] == 0) {
            if (!dfs(j, 3 - c)) return false;
        } else {
            if (color[j] == c) return false;
        }
    }
    return true;
}

int main() {
    // 建图
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    // 多源 dfs
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        // 对没染过色的点进行染色 同时判断合法性
        if (color[i] == 0) {
            if (!dfs(i, 1)) flag = false;
        }
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

