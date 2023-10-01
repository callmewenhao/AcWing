#include <iostream>
#include <cstring>

using namespace std;

const int N = 6007;

int n;
int happy[N];  // 高兴度
int h[N], e[N], ne[N], idx;  // 邻接表
int f[N][2];  // dp 数组
bool has_fa[N]; // 树的根

// 添加一条 a -> b 的点
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// 树形 DP
void dfs(int u) {
    // f[u][0], f[u][1]
    f[u][1] = happy[u];  // 选这个数先加上高兴度
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        dfs(j);  // 先递归处理儿子节点
        
        // 更新
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> happy[i];
    }

    // 初始化 h 并建树
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        has_fa[a] = true;
        add(b, a);
    }

    // 求根节点
    int root = 1;
    while (has_fa[root]) root++; 

    dfs(root);

    // 答案
    cout << max(f[root][0], f[root][1]) << endl;

    return 0;
}



