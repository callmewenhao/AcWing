/**
 * 堆优化的 Dijkstra
 * 
 * 使用优先队列优化 找最小值的过程
 * 
*/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

using PII = pair<int, int>;

const int N = 2e5+7;

int n, m, dist[N];
bool st[N];

// 邻接表存稀疏图
int h[N], w[N], e[N], ne[N], idx;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int Dijkstra() {
    // 初始化距离数组 初始化为最大值
    memset(dist, 0x3f, sizeof dist);

    // 优先队列（堆）
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});  // 放入起点
    dist[1] = 0;

    while (q.size()) {
        auto t = q.top();  // 拿出队头
        q.pop();

        int d = t.first, u = t.second;
        if (st[u]) continue;  // 如果已经计算过最短距离 则跳过
        st[u] = true;
        
        // 更新其余点的距离
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > d + w[i]) {
                dist[j] = d + w[i];  // 更新
                q.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    // 建图
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    // Dijkstra
    cout << Dijkstra() << endl;

    return 0;
}

