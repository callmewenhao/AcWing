/**
 * 图的宽度优先遍历
 * 
 * 图中点的层次
 * 
 * 由于所有边的长度都是 1
 * 那么最短路可以使用宽搜找到
 * 
*/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5+7;

int n, m, d[N];  // 距离数组也用来表示是否遍历过
// 这里是一个有向图 不用 2N
int h[N], e[N], ne[N], idx;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// 从 u 到终点 n 的距离
void bfs(int u) {
    // 初始化 距离数组
    memset(d, -1, sizeof d);

    queue<int> q;
    q.push(u);
    d[u] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        // if (x == n) return;

        for (int i = h[x]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) {
                q.push(j);
                d[j] = d[x] + 1;
            }
        }
    }
}

int main() {
    // 初始化 h 数组
    memset(h, -1, sizeof h);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    bfs(1);
    cout << d[n] << endl;

    return 0;
}



