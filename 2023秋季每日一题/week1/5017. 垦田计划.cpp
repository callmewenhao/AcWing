/**
 * 
 * 题意就是让整体耗时的最大值最小 
 * 
 * 二分答案
 * 
 * 答案的范围：k ~ max{ti}
 * 
 * 假设答案是 x：
 * 
 * 则最大值取 k ~ x-1 都无法实现，而最大值取 x ~ max{ti} 可以实现
 * 
 * 考虑如何实现 check() 函数
 * 
 * 贪心：如果最大值是 x，只需保证所有的耗时都是 x，看现有的条件能否实现这个目标
 * 
 * 样例 1 举例：n=4 m=9 k=2
 * 
 * 假设 x = 4 check 能否成立？
 * 第一块田：t=6 c=1 -> t=4 则耗费资源数量：(6-4)*1 = 2
 * 第二块田：t=5 c=1 -> t=4 则耗费资源数量：(5-4)*1 = 1
 * 第三块田：t=6 c=2 -> t=4 则耗费资源数量：(6-4)*2 = 4
 * 第四块田：t=7 c=1 -> t=4 则耗费资源数量：(7-4)*1 = 3
 * 总共耗费资源数量：10，但是一共只有 9 个，故 x = 4 不成立
 * 
 * 再看 x = 5 check 能否成立？
 * 第一块田：t=6 c=1 -> t=5 则耗费资源数量：(6-5)*1 = 1
 * 第二块田：t=5 c=1 -> t=5 则耗费资源数量：(5-5)*1 = 0
 * 第三块田：t=6 c=2 -> t=5 则耗费资源数量：(6-5)*2 = 2
 * 第四块田：t=7 c=1 -> t=5 则耗费资源数量：(7-5)*1 = 2
 * 总共耗费资源数量：5，我们有 9 个，满足要求，故 x = 5 成立
 * 
 * 综上，答案就是 5 这个分界点，使用二分求解
 * 
 * 时间复杂度是 nlogn
 * 
 * wa 麻了，遇到了两个坑
 * 
 * - 当 check(x) 时 如果 t[i] < x 不需要计算
 * - (t[i] - x) * c[i] 会炸 int，需要开 long long
*/

#include <iostream>

using namespace std;
using LL = long long;

const int N = 1e5 + 7;   // 田的个数

// 相关变量
int n, m, k;
int t[N], c[N];

// check 函数
bool check(int x) {
    LL cnt = 0;  // 使用 long long
    for (int i = 1; i <= n; i++) {
        if (t[i] > x) cnt += LL(t[i] - x) * c[i];  // 计算过程中也要使用 long long
    }
    return cnt <= m;
}

int main() {

    cin >> n >> m >> k;
    int l = k, r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
        r = max(r, t[i]);
    }

    // 闭区间 大于等于模板
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }

    // l 就是第一个 true
    cout << l << endl;

    return 0;
}

