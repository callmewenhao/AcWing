/*
@File    : 3752.cpp
@Author  : wenhao
@Time    : 2023/6/30 9:44
@LC      :
*/
#include <iostream>
#include <string>

using namespace std;

using LL = long long;

const int N = 1e5 + 7, MOD = 1e9 + 7;
int n, m;
char s[N];
int p[N];

int main() {
    int T;
    scanf("%d", &T);

    for (int cases = 1; cases <= T; cases++) {
        scanf("%d %d", &n, &m);
        scanf("%s", s);

        // 预处理 方幂
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = (LL)p[i - 1] * m % MOD;
        }

        // 统计数位
        int res = 0;
        int mid = (n + 1) / 2;  // 可操作的长度
        for (int i = 0; i < mid; i++) {
            // (s[i] - 'a') 是可操作的自由度
            res += (LL)(s[i] - 'a') * p[mid - i - 1] % MOD;
            res %= MOD;
        }

        // 判断最后一个数字是否合法 合法 res += 1;
        int t = 0;
        for (int i = mid - 1, j = n - 1 - i; i >= 0; i--, j++) {
            if (s[i] != s[j]) {
                if (s[i] < s[j])
                    t = 1;
                break;
            }
        }
        res = (res + t) % MOD;
        printf("Case #%d: %d\n", cases, res);
    }
    return 0;
}