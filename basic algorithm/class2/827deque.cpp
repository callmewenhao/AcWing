/**
 * 数组模拟双链表
 * 0 表示左端点 1 表示右端点
 * l[N] 存储左侧节点
 * r[N] 存储右侧节点
 * idx 表示当前可以分配的位置
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int e[N], l[N], r[N], idx;

// 初始化
void init() {
    r[0] = 1, l[1] = 0;
    idx = 2;
}

// 删除第 k 个节点
void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

// 在第 k 个位置右边插入新元素
void add(int k, int x) {
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int m;
    cin >> m;
    // 别忘记初始化
    init();
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
            remove(k+1);
        } else if (op == "IL") {
            cin >> k >> x;
            add(l[k+1], x);
        } else {
            cin >> k >> x;
            add(k+1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) {
        cout << e[i] << " ";
    }
    cout << endl;

    return 0;
}
