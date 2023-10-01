/*
题目有难度

因为数据范围在 1e6 所以时间范围要控制在 On 以内

而且数据含有重复点

计算合法的方案数 = 总方案数 - 不合法的方案数

总方案数 = C(m, 3)

不合法的方案数：不包含圆心的方案数，说明三个点要在一个半圆内

- 枚举每个点，统一计算它右侧这个半圆中的方案数，这样所有的不合法方案数都可以计算出来

- 使用前缀和快速计算出前面这个半圆中的点数，破环成链：复制+加到末尾

- 假设当前枚举的点处有 y 个点，且其右侧半圆有 x 个点，
那么该点处不合法的点数目是：C(y, 1) * C(x, 2) + C(y, 2) * C(x, 1) + C(y, 3)

- 由于这里的组合数最多计算 3 次，所以暴力计算就行

*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 2000010;

int n, m;
int cnt[N], s[N];

LL C(int a, int b)
{
    LL res = 1;
    for (int i = a, j = 1; j <= b; i --, j ++ )
        res = res * i / j;
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ )
    {
        int p;
        scanf("%d", &p);
        cnt[p] ++, cnt[p + m] ++ ;
    }
    for (int i = 1; i < m * 2; i ++ )
        s[i] = s[i - 1] + cnt[i];

    LL res = C(n, 3);
    int len = (m - 1) / 2;
    for (int i = 0; i < m; i ++ )
    {
        int x = s[i + len] - s[i];
        int y = cnt[i];
        res -= C(y, 3) + C(y, 2) * x + y * C(x, 2);
    }

    if (m % 2 == 0)
    {
        for (int i = 0; i < m; i ++ )
        {
            res -= (LL)cnt[i] * cnt[i + m / 2] * (s[i + m / 2 - 1] - s[i]);
            res -= cnt[i] * C(cnt[i + m / 2], 2);
        }
    }

    printf("%lld\n", res);
    return 0;
}
