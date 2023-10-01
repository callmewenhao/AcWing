/*
很综合的一道题目

因为是 0 1 串，并且每个区间的值都知道
那么根据相邻区间的值，就可以确定出 前一个区间的首 和 后一个区间的尾 这两个数的情况：

如果 s[i] == s[i+1] 则这两个数相等
如果 s[i] > s[i+1] 则前一个数等于 1 后一个数等于 0
如果 s[i] < s[i+1] 则前一个数等于 0 后一个数等于 1

使用并查集维护相等的数，同时维护一个存值的数组
这样就可以得到每个区间内数的情况了

其实，只要第一个区间确定后，后面的区间就都确定了

已经知道第一个区间内 0 1 的情况，答案就是，在那些没确定 0 1 的位置中，求一个组合数

*/
#include <iostream>
#include <cstring>

using namespace std;

using LL = long long;

const int N = 1e6+7, MOD = 1e6+3;

int n, m;
int s[N];

// 并查集相关
int p[N], v[N]; 

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

// 组合数 2 快速幂逆元求组合数
// 快速幂
int qmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1LL * res * a % p;
        a = 1LL * a * a % p;
        b >>= 1;
    }
    return res;
}

// C_a^b
int C(int a, int b) {
    // 把阶乘的值求出来，然后计算逆元
    int fa = 1, fb = 1, fab = 1;
    for (int i = 1; i <= a; i++) fa = 1LL * fa * i % MOD; 
    for (int i = 1; i <= b; i++) fb = 1LL * fb * i % MOD; 
    for (int i = 1; i <= a - b; i++) fab = 1LL * fab * i % MOD; 
    return 1LL * fa * qmi(fb, MOD - 2, MOD) * qmi(fab, MOD - 2, MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) p[i] = i, v[i] = -1;
    for (int i = 0; i < n - m + 1; i++) cin >> s[i];

    // 枚举相邻两个区间对 维护并查集
    for (int i = 0, j = m; i < n - m; i++, j++)
        // 如果两个区间值相等 则 v[i] = v[j]
        if (s[i] == s[i+1]) 
            p[find(j)] = find(i);
    
    // 枚举相邻两个区间对 确定某些值
    for (int i = 0, j = m; i < n - m; i++, j++)
        if (s[i] > s[i+1]) 
            v[find(i)] = 1, v[find(j)] = 0;
        else if (s[i] < s[i+1])
            v[find(i)] = 0, v[find(j)] = 1;
    
    // 计算第一个区间中 0 1 的数量
    int c0 = 0, c1 = 0;
    for (int i = 0; i < m; i++) {
        int t = v[find(i)];
        if (t == 0) c0++;
        else if (t == 1) c1++;
    }

    // 输出组合数
    cout << C(m - c0 - c1, s[0] - c1) << endl;

    return 0;
}

