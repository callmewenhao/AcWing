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

const int N = 1e5+7;

int head, e[N], ne[N], idx;

//初始化链表
void init() {
    head = -1, idx = 0;
}

// 表示向链表头插入一个数 x
void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

// 在第 k 个插入的数后面插入一个数 x
// 注意 k 从 1 开始，但是 idx 是从 0 开始的，所以应该传入 k-1
void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

// 删除第 k 个插入的数后面的数
// 注意应该传入 k-1
void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {

    init();

    int m;
    cin >> m;
    while (m--) {
        char op;
        int k, x;
        cin >> op;

        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if (op == 'D') {
            cin >> k;
            // 特判删除头节点
            if (k == 0) head = ne[head];
            else remove(k-1);
        } else if (op == 'I') {
            cin >> k >> x;
            add(k-1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }

    return 0;
}





