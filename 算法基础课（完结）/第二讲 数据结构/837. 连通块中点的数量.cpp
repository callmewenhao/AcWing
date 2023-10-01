/**
 * UF 中连通量的大小
 */
#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int p[N], si[N];  // 注意只保证根节点的 size 有意义

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    si[px] += si[py];  // 维护根节点的 size
    p[py] = px;
}

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        si[i] = 1;
    }

    // 处理 op
    string op;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == "C") {
            cin >> a >> b;
            // 合并
            if (a != b) merge(a, b);
        } else if (op == "Q1") {
            cin >> a >> b;
            // 判断是否在一个连通量
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else if (op == "Q2") {
            cin >> a;
            // 返回父节点的 si
            cout << si[find(a)] << endl;
        }
    }

    return 0;
}


