/**
 * 一维差分
 * 就是一维前缀和的逆操作
*/

#include <iostream>

using namespace std;

const int N = 1e5 + 7;
int a[N], d[N];

// 差分不用考虑如何构造 只需知道如何修改 然后借助修改构造
// 区间 [l, r] 中的每个元素修改 c
void insert(int l, int r, int c) {
    d[l] += c;
    d[r+1] -= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 初始化差分数组
    for (int i = 1; i <= n; i++) {
        insert(i, i, a[i]);
    }

    // 差分操作
    for (int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }

    // 在差分数组上求答案
    for (int i = 1; i <= n; i++) {
        d[i] += d[i-1];
        cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}
