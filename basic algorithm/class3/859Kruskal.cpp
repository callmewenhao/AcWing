/**
 * 最小生成树 MST
 *
 * Kruskal 算法
 *
 *
 * 算法流程：
 * 对边按照 边权 排序
 * 然后遍历 这些排好序 的边
 * 使用 并查集 把未联通的点联通 同时维护 MST 的权重
 * 
 * 时间复杂度 mlogm
 * 
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>

using namespace std;

const int N = 1e5 + 7, M = 2e5 + 7;

// 边数组  注意这可不是结构体😁 这是类
struct EDGE {
    int u, v, w;
} edges[M];

// 比较函数
bool cmp(EDGE a, EDGE b) {
    return a.w < b.w;
}

// p[N] 是 uf 祖宗集合
int n, m, p[N];  

// 查找函数
int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    // 录入边
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    // 排序
    sort(edges, edges + m, cmp);

    // Kruskal
    // 初始化UF
    iota(p, p + n + 1, 0);
    int ans = 0, cnt = 0;  // cnt 不是节点数 而是 使用的边数
    for (int i = 0; i < m; i++) {
        auto [u, v, w] = edges[i];
        // 跳过 自己 以及 已经 merge 的节点
        if (u == v || find(u) == find(v))
            continue;
        p[find(u)] = find(v);  // merge
        ans += w;
        cnt += 1; // 边数 +1
    }

    if (cnt != n-1)  // 应该有 n-1 条边
        cout << "impossible" << endl;
    else
        cout << ans << endl;

    return 0;
}
