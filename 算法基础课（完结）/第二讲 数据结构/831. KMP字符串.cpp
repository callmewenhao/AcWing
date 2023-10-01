/**
 * KMP 字符串匹配 时间复杂度 O(n+m)
 *
 * 原串 s[N] 下标从 1 开始
 * 目标串（模式串）p[N] 下标从 1 开始
 *
 * next[i] = j 表示以 i 为终点的后缀 所能匹配的 最长的 与之相等的前缀长度是 j
 * 也就是 p[1, j] = p[i-j+1, i] 且 j 最大
 *
 * 匹配过程：双指针 i 指向原串 j 指向目标串
 *
 * 当 s[i-j,i-1] = p[1, j]，但是 s[i] != p[j+1] 时
 * 递归地使用 next[j] 对应的前缀（或者后缀） 来匹配 s[i-j,i-1]
 * 如果 在某次匹配时 s[i] == p[j+1] 则递归结束，继续向前移动双指针
 *
 * 可以想象 如果递归过程中 没有发生 s[i] == p[j+1]
 * 那意味着最终要下标从 1 匹配，也就回归到暴力了
 *
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 7, M = 1e6 + 7;

int n, m;
char p[N], s[M];
int ne[N];  // next 数组

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> p + 1 >> m >> s + 1;

    // 求 next 数组
    // 注意前缀和后缀不能完全重合 
    // 所以 next[1] = 0 我们从 2 开始计算 next[i]
    // next[1] = 0 的另一种解释：当第一个字符都不相等，成功匹配的长度就是 0 啦
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        // 记录一下这个匹配成功的 next 数组值
        ne[i] = j;
    }

    // KMP 匹配过程
    // i 表示目标串正要匹配的字符下标
    // j 表示成功匹配的模式串的长度 
    // p[j + 1]是模式串要和目标串匹配的字符
    for (int i = 1, j = 0; i <= m; i++) {
        // 当已经有匹配的长度 并且 要匹配的字符不相等 修改成功匹配的长度
        while (j && s[i] != p[j + 1])
            j = ne[j];
        // 相等就继续向下走
        if (s[i] == p[j + 1])
            j++;
        if (j == n) {
            // 匹配成功 输出下标
            cout << i - n << " ";
            j = ne[j];  // 匹配成功后 往后退步 但是不必从 1 开始 仍然从能匹配的最大长度开始
        }
    }
    cout << endl;

    return 0;
}
