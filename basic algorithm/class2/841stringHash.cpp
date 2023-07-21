/**
 * 字符串 hash
 *
 * 字符串前缀 hash 法
 * 把字符串看成是一个 p 进制的数
 * 然后把 p 进制的数转成 10 进制的数 并模 Q
 *
 * 注意
 * 一般不能把字母映射成 0 而是从 1 开始
 * 不考虑冲突情况 在取 p = 131 or 13331 & Q = 2^64 时 99.99% 不会冲突
 * 另外 我们可以使用 unsigned long long 存数字 这样当数字溢出时 就会自动取模
 *
 * 利用前缀 hash 求出所有字串 hash
 * 已知 h[l-1] h[r] 求出字串 [l, r] 的 hash 值
 * 公式 h[r] - h[l - 1] * p ^ (r - l + 1)
 * 注意 左边是高位 右边是低位
 *
 */

#include <iostream>

using namespace std;

using ULL = unsigned long long;

const int N = 1e5 + 7, P = 131;

int n, m;
char str[N];
ULL h[N], p[N];

int get(int l, int r) {
    // 公式很精妙
    return h[r] - h[l-1] * p[r-l+1];
}

int main() {
    cin >> n >> m;
    cin >> str + 1;

    // 处理方幂 和 字符串前缀 hash
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + str[i];
    }

    // 询问
    int l1, r1, l2, r2;
    while (m--) {
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}