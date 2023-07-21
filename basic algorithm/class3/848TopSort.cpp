/**
 * 拓扑排序
 *
 * 有向图的拓扑序列
 * 只有 有向无环图 才能进行拓扑排序
 *
 * 使用宽搜的框架
 * 首先 入队入度为零的点
 * 然后 使用宽搜的框架 每次 pop 出队头 更新其余点的入度
 * 遇到新的 入度为零的点后 入队
 * 直到队列为空
 *
 * 可以用来找到拓扑序 或者 判断有向图是否有环
 * 注意拓扑序并不唯一
 *
 * 由于需要保存 拓扑序
 * 使用模拟队列更方便😁
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int n, m;
// 邻接表
const int N = 1e5 + 7;
int h[N], e[N], ne[N], idx;
// 模拟队列
int q[N], hh, tt = -1;
// 入度组数
int inDegree[N];


void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort() {
    // 入度为零的点入队
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q[++tt] = i;
    }
    // 当队列不空
    while (hh <= tt) {
        int u = q[hh];
        hh++;

        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            inDegree[j]--;
            if (inDegree[j]  == 0) q[++tt] = j;
        }
    }
    return hh == n; // tt == n-1
}

int main() {
    // 初始化
    memset(h, -1, sizeof h);

    // 建图
    cin >> n >> m;
    for (int i = 0 ;i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        // 增加入度
        inDegree[b]++;
    }

    // 拓扑排序 & 打印
    if (topsort()) {
        // 这里要从零开始打印
        for (int i = 0; i < n; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    } else cout << -1 << endl;
    
    return 0;
}
