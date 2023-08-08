#include <iostream>
#include <cstring>

using namespace std;
using LL = long long;

const int N = 1007, MOD = 1e9+7;

// 方法2
int n, f[N][N];

int main() {
    cin >> n;
    // 0 个物品组成 0 有 1 种方案数
    f[0][0] = 1;
    // 枚举和
    for (int i = 1; i <= n; i++) {
        // 枚举个数
        for (int j = 1; j <= i; j++) {
            f[i][j] = (f[i-1][j-1] + f[i-j][j]) % MOD;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res = (res + f[n][i]) % MOD;

    cout << res << endl;

    return 0;
}

// 一维完全背包
/*
int n, f[N];

int main() {
    cin >> n;
    // 初始化
    f[0] = 1;
    // 枚举物品
    for (int i = 1; i <= n; i++) {
        // 枚举体积
        // 完全背包 正向枚举就行
        for (int j = i; j <= n; j++) {
            // 计算方案数
            f[j] = ((LL)f[j] + f[j-i]) % MOD;
        }
    }
    cout << f[n] << endl;
    return 0;
}
*/
// 二维完全背包
/*
int n, f[N][N];

int main() {

    cin >> n;
    // 初始化 f[0]，其余 f[i] 可以通过递推公式求出
    // 0 组成 0 有 1 种方案数，而 0 组成 i 没有方案数
    f[0][0] = 1;  
    
    // 完全背包模板
    // 枚举物品
    for (int i = 1; i <= n; i++) {
        // 枚举背包体积
        for (int j = 0; j <= n; j++) {
            // 不选 i 个物品
            f[i][j] = f[i-1][j];
            // 能选 i 个物品 则方案数相加
            if (j >= i)
                f[i][j] = ((LL)f[i][j] + f[i][j-i]) % MOD;
        }
    }

    cout << f[n][n] << endl;

    return 0;
}
*/






