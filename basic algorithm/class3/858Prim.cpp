/**
 * 最小生成树
 * 
 * 定义（给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数）
 * 给定一张边带权的无向图 G = (V, E) 
 * 其中 V 表示图中点的集合 E 表示图中边的集合 n = |V| m = |E|
 * 由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，
 * 其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。
 * 
 * Prim 算法
 * 朴素 Prim 算法和 dijkstra 算法类似
 * 我倾向于写优先队列优化的版本
 * 
 * 算法流程：
 * 所有距离初始化为正无穷
 * n 次迭代：
 *  每次找到 不在生成树中的 距离生成树最近 的点 t
 *  用 t 更新其他点到生成树的距离
 *  最后 把 t 放入集合
 * 
 * 时间复杂度 mlogn
 * 
*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using PII = pair<int, int>;

const int N = 507;

int n, m;
int g[N][N];
bool st[N];  // 表示在不在 MST 中

int main() {
    cin >> n >> m;

    // 注意 0x3f3f3f3f 表示不连通
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++) {
        g[i][i] = 0;  // 其实不应该自己走向自己 不符合 MST 的定义
    }

    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        if (u == v) continue;  // 同上 不应该自己走向自己
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }

    // prim
    int ans = 0, cnt = 0;  // ans MST 的权重  cnt 记录联通块的大小
    priority_queue<PII, vector<PII>, greater<>> q;  // 优先队列
    q.push({0, 1});  // 放入任意一个都行

    while (q.size()) {
        // 使用 距离生成树最近 的点 t
        auto [w, t] = q.top();
        q.pop();

        if (st[t]) continue;
        st[t] = true;
        // 维护答案
        ans += w;
        cnt++;
        // cout << t << " " << ans << " " << cnt << endl;

        // 更新其他点到生成树的距离
        for (int i = 1; i <= n; i++) {
            // 跳过自己 以及 不连通的点
            if (i == t || g[t][i] == 0x3f3f3f3f) continue;
            q.push({g[t][i], i});
        }
    }

    if (cnt != n) cout << "impossible" << endl;
    else cout << ans << endl;

    return 0;
}





