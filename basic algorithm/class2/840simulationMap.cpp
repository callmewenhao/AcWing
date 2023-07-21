/**
 * 模拟散列表
 *
 * 存储结构 开放寻址法 拉链法
 *
 * 拉链法
 * 先把数字（-1e9~1e9）映射到 0~1e5+3 个槽中（末尾的数字建议是质数）
 * 然后在 0~1e5+3 的每个槽建一个链表存数字（数组模拟即可）
 *
 * 开放寻址法
 * 只开了一个数组 数据范围的 2~3 倍
 * 如果当前坑位有人 就继续向后找位置
 *
 */
#include <cstring>
#include <iostream>

using namespace std;

// 开数据范围的两倍 null 表示空
const int N = 2e5 + 3, null = 0x3f3f3f3f;

// 开放寻址法
int h[N];

// 找到 x 应该在 hash 中的位置
int find(int x) {
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x) {
        k++;
        if (k == N)
            k = 0;  // 循环看第一个坑位
    }
    return k;
}

int main() {
    // 初始化 槽
    memset(h, 0x3f, sizeof(h));  // -1 表示槽上没有元素（为空）

    int n;
    cin >> n;

    char op;
    int x;
    while (n--) {
        cin >> op >> x;
        int k = find(x);
        if (op == 'I') {
            h[k] = x;
        } else if (op == 'Q') {
            if (h[k] == x)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}

/*
// 拉链法
const int N = 1e5+3; // 映射数组（槽）的大小

int h[N], e[N], ne[N], idx;

// 插入
void insert(int x) {
    int t = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[t];
    h[t] = idx++;
}

// 查询
bool find(int  x) {
    int t = (x % N + N) % N;
    // 遍历链表
    for (int i = h[t]; ~i; i = ne[i]) {
        if (e[i] == x) return true;
    }
    return false;
}

int main() {
    // 初始化 槽
    memset(h, -1, sizeof(h));  // -1 表示槽上没有元素（为空）

    int n;
    cin >> n;

    char op;
    int x;
    while (n--) {
        cin >> op >> x;
        if (op == 'I') {
            insert(x);
        } else if (op == 'Q') {
            if (find(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
*/
