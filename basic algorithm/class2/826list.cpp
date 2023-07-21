/**
 * 数组模拟单链表 静态链表🤗
 *
 * head  表示链表的当前的头节点
 * e[N]  存储节点的 value
 * ne[N]  存储节点的 next
 * idx  表示当前可以分配的位置  从 0 开始
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 7;
int head, e[N], ne[N], idx;

// 初始化
void init() {
    head = -1;  // 表示空链表
    idx = 0;    // 从零开始分配
}

// 将 x 插到头节点
void add_to_head(int x) {
    e[idx] = x, ne[idx] = head;
    head = idx, idx++;
}

// 将 x 插到 下标是 k 的点 后面
void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k];
    ne[k] = idx, idx++;
}

// 将下标是 k 的点 后面的点删掉
void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int m;
    cin >> m;

    init();
    while (m--) {
        char op;
        cin >> op;
        if (op == 'H') {
            int x;
            cin >> x;
            add_to_head(x);
        } else if (op == 'I') {
            int k, x;
            cin >> k >> x;
            add(k - 1, x);
        } else if (op == 'D') {
            int k;
            cin >> k;
            if (k == 0) head = ne[head];
            else remove(k-1);
        }
    }

    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }
    cout << endl;

    return 0;
}