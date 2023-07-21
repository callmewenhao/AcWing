/**
 * 堆排序
 *
 * 堆是一棵完全二叉树
 * 使用一个一维数组存储 注意下标从 1 开始
 *
 * 小根堆 每个节点的值小于等于儿子的值
 * 节点 i 的 左儿子 i*2 右儿子 i*2+1
 *
 * 核心操作
 * down() 元素下沉操作 下沉到合适的位置
 * up() 元素上浮操作 上浮到合适的位置
 *
 * 插入新元素
 * 在堆的最后插入一个新元素 然后把这个数上浮到合适的位置
 *
 * 求最小值
 * 由于维护的是最小堆 则最小值就是堆的第一个元素
 *
 * 删除最小值
 * 很有技巧性 把堆中最后一个元素覆盖堆顶 然后堆大小减一 再下沉操作 down(1)
 *
 * 删除任意元素 比如删除第 k 个元素
 * 与删除最小值类似 把第 k 个元素用堆中最后一个元素覆盖 然后堆大小减一
 * 然后 down(k) up(k) 其实 down(k) up(k) 不会全部执行 只会走其中一个
 *
 * 修改任意元素 比如修改第 k 个元素
 * 把第 k 个元素用新值覆盖 然后 down(k) up(k) 不会全部执行 只会走其中一个
 *
 * O(n) 建堆 从 n/2 开始 down()
 *
 */
#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int n, m;
int h[N], si;

// 下沉
void down(int x) {
    int t = x;
    if (2 * x <= si && h[2 * x] < h[t]) t = 2 * x;
    if (2 * x + 1 <= si && h[2 * x + 1] < h[t]) t = 2 * x + 1;
    if (x != t) {
        swap(h[x], h[t]);
        down(t);
    }
}

int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    si = n;

    // 数组堆化
    for (int i = n / 2; i; i--) {
        down(i);
    }

    // 前 m 个元素
    while (m--) {
        cout << h[1] << " ";
        // 覆盖 h[1] & down(1)
        h[1] = h[si];
        si--;
        down(1);
    }
    cout << endl;
    return 0;
}

