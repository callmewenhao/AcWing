/**
 * 数组模拟双链表
 * 0 表示左端点 1 表示右端点 后续插入的点从 2 开始
 * l[N] 存储左侧节点
 * r[N] 存储右侧节点
 * idx 表示当前可以分配的位置
 */

#include <iostream>
#include <string>

using namespace std;

const int N = 1e5+7;

int m, e[N], l[N], r[N], idx;

// 初始化
void init() {
    // 0 表示左端点，1 表示右端点
    r[0] = 1, l[1] = 0;
    idx = 2;  // 注意是从 2 开始的
}

// 在第 k 个点的右边插入一个点
void add(int k, int x) {
    e[idx] = x;
    // 新插入点的右边 = k点的右边
    r[idx] = r[k];
    // 新插入点的左边 = k
    l[idx] = k;
    // 修改之前的边
    l[r[k]] = idx; // l[r[idx]] = idx
    r[k] = idx++; // r[l[idx]] = idx
}

// 在第 k 个点的左边插入一个点
// == 在第 l[k] 个点的右边插入一个点
// 就是 add(l[k], x)

// 删除第 k 个插入的节点
void remove(int k) {
    // 让左边的右边 = 我的右边
    r[l[k]] = r[k];
    // 让右边的左边 = 我的左边
    l[r[k]] = l[k];
}

int main() {
    init();

    int m;
    cin >> m;

    while (m--) {
        string op;
        int k, x;
        cin >> op;

        if (op == "L") {
            cin >> x;
            add(0, x);
        } else if (op == "R") {
            cin >> x;
            add(l[1], x);
        } else if (op == "D") {
            cin >> k;
            // +1 是因为 idx 从 2 开始
            remove(k+1);
        } else if (op == "IL") {
            cin >> k >> x;
            add(l[k+1], x);
        } else if (op == "IR") {
            cin >> k >> x;
            add(k+1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) {
        cout << e[i] << " ";
    }

    return 0;
}
