/**
 * 模拟堆
 *
 * 平时用 STL 中的 priority_queue
 * 最短路可以使用堆优化
 * 这个题目难在 swap 的时候把 插入的顺序也交换好
 * ph 由左边指向右边
 * hp 由右边指向左边
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;

// ph[k] 第 k 个插入的数对应堆中的下标
// hp[i] 堆中下标是 i 的元素对应插入的顺序
int h[N], ph[N], hp[N], cnt;

// 交换
void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}    
// 下沉
void down(int x) {
    int t = x;
    if (2 * x <= cnt && h[2 * x] < h[t]) t = 2 * x;
    if (2 * x + 1 <= cnt && h[2 * x + 1] < h[t]) t = 2 * x + 1;
    if (x != t) {
        heap_swap(x, t);
        down(t);
    }
}

// 上浮
void up(int x) {
    while (x / 2 && h[x] < h[x / 2]) {
        heap_swap(x, x / 2);
        x /= 2;
    }
}

int main() {
    int n, m = 0;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;

        int k, x;
        if (op == "I") {
            cin >> x;
            cnt++;
            m++;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            // 插入之后要上浮
            up(cnt);
        } else if (op == "PM") {
            cout << h[1] << endl;
        } else if (op == "DM") {
            heap_swap(1, cnt);
            cnt--;
            // 删除最小值之后要下沉
            down(1);
        } else if (op == "D") {
            cin >> k;
            k = ph[k];
            heap_swap(k, cnt);
            cnt--;
            // 删除中间的要上浮或者下沉
            up(k);
            down(k);
        } else if (op == "C") {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            // 修改中间的要上浮或者下沉
            up(k);
            down(k);
        }
    }

    return 0;
}