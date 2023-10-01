/**
 * 有边数限制的最短路
 *
 * bellman-ford 算法
 *
 * 可以处理有负权边的图
 * 注意当图中存在负权回路时，是没有最短路的
 * bellman-ford 算法 也可以判断是否存在负权回路
 * 但一般不用他来做🙂 使用 spfa 来做
 *
 * 有一种题型只能用 bellman-ford 解决：有边数限制的最短路😁
 *
 * 算法流程：
 *  for k from 1 to n // n 次
 *      // 注意这里的 k 具有实际的意义
 *      for all edges: a, b, w  // m 次
 *          // 松弛操作
 *          dist[b] = min(dist[b], dist[a] + w)  // 更新距离
 *
 * 时间复杂度 O(nm)
 *
 * 第一层循环中 k 的实际含义：
 * 循环 k 次后求得的最短距离是 经过不超过 k 条边走到每一个点的最短距离
 * 所以，当 k == n 时，如果发生更新，
 * 则意味着存在一条长度为 n 的边（也是一个环）更新了最短距离
 * 那这一定是一个负环
 *
 * 执行 bellman-ford 算法后，所有点满足
 * dist[b] <= dist[a] + w  这个就是三角不等式
 *
 * 存边的方式很随意 直接写一个结构体数组就可以
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 507, M = 10007;

struct Edge {
    int a, b, w;
} edges[M];  // M 条边

int n, m, k;
int dist[N], last[N];

void bellman_ford() {
    // 初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;  // 注意这个要初始化

    // 遍历 k 次
    for (int i = 0; i < k; i++) {
        // 备份上一次的松弛结果 放置发生串联
        memcpy(last, dist, sizeof dist);
        // 遍历所有的边
        for (int j = 0; j < m; j++) {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.w);
        }
    }
}

int main() {
    // 存边
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    // bellman-ford 算法
    bellman_ford();
    // 注意这里是 0x3f3f3f3f / 2 因为 +inf 可能会被负权更新
    if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
    else cout << dist[n] << endl;

    return 0;
}
