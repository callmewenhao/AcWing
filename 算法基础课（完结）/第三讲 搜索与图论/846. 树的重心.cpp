/**
 * 图的深度优先遍历
 *
 * 如果一个图中包含 n 个结点（编号 1∼n）和 n−1 条无向边
 * 那这就是一棵树（无环连通图）
 *
 * 树的重心
 *
 * 树的重心定义：树中的某个节点，把这个节点删掉后，剩余各个连通块数量的最大值最小
 * 也就是 以树的重心 为根的所有子树中点的数量的最大值最小
 *
 * 把树中的某个节点删掉后，树会被分成 3 个部分，分别是
 * 树的左、右儿子
 * 以及其余不包含 以该节点为根的子树 的部分
 * 该部分节点的数量就是 n - 1 - 左子树 - 右子树
 *
 * 时间复杂度 On 每一个点都会被遍历
 *
 */

#include <iostream>
#include <cstring>
using namespace std;

// 邻接表存图（链式前向星）
// 由于是无向图 边的数目是点数目的 2 倍 开 2 * N
int n;
const int N = 1e5 + 7, M = 2 * N;
int h[N], e[M], ne[M], idx;
bool vis[N]; // 表示该点是否遇到过
int ans = N;  // 答案必须得是全局的

// 建立一条 a -> b 的边
void add(int a, int b) {
    e[idx] = b;  // 当前节点指向 b
    ne[idx] = h[a];  // 把当前节点放到 a 的链子上 且 idx++
    h[a] = idx++;
}

// 深度优先遍历
// 返回以 u 为根的子树中点的数量
int dfs(int u) {
    vis[u] = true;
    int res = 1, mx= 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!vis[j]) {
            int t = dfs(j);
            mx = max(mx, t);
            res += t;
        }
    }
    // 用子树节点数量的最大值更新答案
    mx = max(mx, n - res);
    ans = min(ans, mx);
    return res; // 返回这棵树的节点个数
}

int main() {
    // 图初始化
    memset(h, -1, sizeof h);
    // 建图
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    
    // 深搜
    dfs(1);
    cout << ans << endl;
    return 0;
}
