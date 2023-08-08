#include <iostream>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << N;

int n;
int f[M][N], w[N][N];

int main() {

    cin >> n;
    for (int i = 0;  i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    // 初始化 f
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;  // 刚开始在 0 这个点上，所以状态的第 0 位是 1，故为 1，然后以 0 结尾

    // 枚举状态
    for (int i = 0; i < 1 << n; i++) {
        // 枚举终点
        for (int j = 0; j < n; j++) {
            // 如果状态 i 以终点 j 结尾 
            if (i >> j & 1) {
                // 枚举 k 点
                for (int k = 0; k < n; k++) {
                    // 判断状态 i 去掉 j 点之后的集合 是否含有 k 点
                    if ((i ^ (1 << j)) >> k & 1)
                        f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + w[k][j]);
                }
            }
        }
    }
    // 答案就是 f[(1 << n) - 1][n-1]
    cout << f[(1 << n) - 1][n-1] << endl;

    return 0;
}





