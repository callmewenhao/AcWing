/**
 * 多重背包其实是01背包的扩展
 * 一维优化时也是需要逆序遍历
 * 
 * 这个题目的数据范围是：100，所以可以使用 n^3 的算法
*/
#include <iostream>

using namespace std;

const int N = 110;

// 二维
/*
int n, m;
int v[N], w[N], s[N], f[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++) {
                f[i][j] = max(f[i][j], f[i-1][j - k*v[i]] + k*w[i]);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
*/

// 一维
int n, m;
int v[N], w[N], s[N], f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }
    // 枚举物品种类
    for (int i = 1; i <= n; i++) {
        // 逆序枚举容量
        for (int j = m; j >= 0; j--) {
            // 枚举个数
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++) {
                f[j] = max(f[j], f[j - k*v[i]] + k*w[i]);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}


