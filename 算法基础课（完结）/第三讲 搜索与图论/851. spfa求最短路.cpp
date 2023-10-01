/**
 * spfa 算法
 * 
 * 使用 spfa 求最短路 解决含负权但是不含负环的图
 * 
 * spfa 算法是对 bellman-ford 算法的优化
 * bellman-ford 算法中更新距离 dist[b] = min(dist[b], dist[a] + w) 是冗余的
 * 很多情况下 dist[b] 不会更新 只有 dist[a] 跟新之后 dist[b] 才有可能更新  
 * 
 * spfa 算法使用一个队列（和宽搜相似）进行优化
 * 队列中存放 所有最短路变小的节点 用于更新其他点
 * 
 * 算法流程（和 dijkstra 类似）：
 *  queue <- 1
 *  while queue not empty：
 *      t <- q.front
 *      q.pop
 *      更新 t 的所有出边 t -> b, w
 *      q <- b  // 注意要防止队列存重复的点 没有意义
 *      
 * 时间复杂度：一般 O(m) 最坏 O(nm)
 * 
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5+7;

int n, m;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool st[N]; 

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;

        // 遍历 t 的边
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {  // 能不能放入 j
                    q.push(j);
                    st[j] = true; 
                }
            }
        }
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);

    // 初始化
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    // spfa 算法
    spfa();

    // 这里直接比较 0x3f3f3f3f 就行
    // 这个不需要 因为队列里都是由起点更新到的点
    // 不存在bellman-ford算法中未更新的点同样被边更新的情况。
    if (dist[n] == 0x3f3f3f3f) cout << "impossible" << endl;
    else cout << dist[n] << endl;

    return 0;
}

