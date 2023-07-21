/**
 * 并查集
 *
 * 近乎 O1 完成下面两个操作
 *
 * 1. 将两个集合合并
 * 2. 询问两个元素是否在一个集合中
 *
 * 基本原理：
 * 每个集合用用一棵树来表示
 * 树根的编号就是整个集合的编号
 * 每个节点存储它的父节点 p[x] 表示 x 的父节点
 *
 * 判断树根
 * if(p[x] == x) {}
 *
 * 求 x 的集合编号
 * while (p[x] != x) x = p[x];
 *
 * 合并集合
 * px 是 x 的集合编号 py 是 y 的集合编号
 * p[x] = y  or p[x] = py
 *
 * 路径压缩优化
 * 在查找的时候进行路径优化
 *
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 7;

// 祖先数组
int p[N];

// 查找根节点（编号）
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]); // 路径压缩
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化 p[n]
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    // 处理 op
    char op; 
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> op >> a >> b;
        if (op == 'M') {
            p[find(a)] = find(b);  // 合并操作
        } else if (op == 'Q') {
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
