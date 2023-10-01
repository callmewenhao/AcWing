#include <iostream>
#include <cstring>

using namespace std;

const int N = 303, INF = 1e9;


// 递推
int n;
int s[N];  // 前缀和
int f[N][N];  // dp 数组

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i-1];
    }
    // 先枚举区间长度
    // 长度为 1 的区间 f[i][j] = 0
    for (int len = 2; len <= n; len++) {
        // 枚举区间左端点
        for (int i = 1; i + len - 1 <= n; i++) {
            // 计算区间右端点
            int j = i + len - 1;
            // 枚举拆分区间的位置
            f[i][j] = 1e9;
            for (int k = i; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] + s[j] - s[i-1]);
            }
        }
    }
    // 输出答案
    cout << f[1][n] << endl;
}


// 记搜
/*
int n, a[N], s[N], f[N][N];

int dfs(int i, int j) {
    if (f[i][j] != -1) return f[i][j];

    if (i == j) return f[i][j] = 0;
    // 枚举拆分成两个区间的位置
    // [i, j]->[i, k]和[k+1, j]
    int res = INF;
    for (int k = i; k < j; k++) {
        res = min(res, dfs(i, k) + dfs(k+1, j) + s[j] - s[i-1]);
    }
    return f[i][j] = res;
}

int main() {

    cin >> n;
    memset(f, -1, sizeof f);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // 求前缀和
        s[i] = s[i-1] + a[i];
    }
    // 记搜求答案
    int res = dfs(1, n);
    // 输出答案
    cout << res << endl;

    return 0;
}
*/






