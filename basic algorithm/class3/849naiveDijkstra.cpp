/**
 * 单源最短路
 * 
 * 朴素 Dijkstra
 * 
 * 基本思路🧐
 * 
 * 初始化距离 d[1] = 0, d[i] = +inf
 * 
 * 维护 集合 S：当前已经确定最短路（距离）的点
 * 一般我们维护 集合 S 的补集 S^All：当前未确定最短路（距离）的点
 * 
 * 遍历 n 次 （毕竟只有 n 个点）
 * 找到 S 的补集中的最小值点 把该点放到 S 中  这里是基于贪心的思想
 * 然后更新 S 的补集中其余点的最短路
 * 直到遍历结束
 * 
 * 时间复杂度 On^2
 * 一个 n 用于遍历 n 次，另一个 n 用于找到最小值
 * PS：
 * Dijkstra 主要思想是贪心
 * 最短路问题不区分 有向边 还是 无向边
 * 无向边当作两条有向边
 * Dijkstra 要求不能存在负权边
 * 
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 507;

int n, m;
int g[N][N];  // 这里使用邻接矩阵存图
int d[N];  // 存最短路
bool st[N];  // 记录是否已经找到最短路

int Dijkstra() {
    // 初始化距离
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    // 遍历 n-1 次就行
    for (int i = 1; i < n; i++) {
        // 找到当前未确定最短路点中最小的点
        int t = -1;
        for (int j = 1; j <= n; j++) {
            // 保证每找到过最小值
            if (!st[j] && (t == -1 || d[t] > d[j])) {
                t = j;
            }
        }
        // 用找到的点更新剩余点的最短路
        // 注意 自环的权重全是正值 所以不会造成影响
        st[t] = true;  // 加入集合 S
        for (int j = 1; j <= n; j++) {
            d[j] = min(d[j], d[t] + g[t][j]);
        }
    }
    if (d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}

int main() {
    // 初始化
    memset(g, 0x3f, sizeof g);

    // 建图
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    // 朴素 Dijkstra
    int ans = Dijkstra();
    cout << ans << endl;

    return 0;
}
