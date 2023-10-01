/**
 * 滑动窗口最值
 *
 * 单调队列 存放的是 下标⚠️
 * 
 * C++ 中 有序集合 multiset 一样的功能 但是 nlogn
 *
 */
#include <iostream>

using namespace std;

const int N = 1e6 + 7;

// 模拟队列
int a[N], q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // min
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        // 处理右侧
        while (hh <= tt && a[q[tt]] >= a[i]) {
            tt--;
        }
        q[++tt] = i;
        // 处理左侧
        // 这里用 if 就可以，根据题意最多只有1个对头不满足要求
        if (q[hh] <= i - k) {
            hh++;
        }
        // min is q[hh]
        if (i >= k - 1) cout << a[q[hh]] << " ";
    }
    cout << endl;

    // max
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        while (hh <= tt && a[q[tt]] <= a[i]) {
            tt--;
        }
        q[++tt] = i;
        if (q[hh] <= i - k) {
            hh++;
        }
        if (i >= k - 1) cout << a[q[hh]] << " ";
    }
    cout << endl;
    return 0;
}
