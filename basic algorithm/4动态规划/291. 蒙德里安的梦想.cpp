#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

using LL = long long;

const int N = 12, M = 1 << N;

int n, m;
LL f[N][M];  // dp 数组
vector<int> state[M];  // 可以转移到 j 的状态 k 需要预处理
bool st[M]; // 状态是否合法 需要预处理

int main() {
    while (cin >> n >> m, n || m) {
        // 预处理 st[M]
        for (int i = 0; i < 1 << n; i++) {
            int cnt = 0;
            bool is_valid = true;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    if (cnt & 1) {
                        is_valid = true;
                        break;
                    }
                    cnt = 0;
                } else
                    cnt++;
            }
            // 如果有最后一段零
            if (cnt & 1) is_valid = false;
            st[i] = is_valid;
        }

        // 预处理 state[M]
        for (int i = 0; i < 1 << n; i++) {
            state[i].clear();
            for (int j = 0; j < 1 << n; j++) {
                // 合法的状态 k 需要满足的条件
                if ((i & j) == 0 && st[i | j]) {
                    state[i].push_back(j);
                }
            }
        }

        memset(f, 0, sizeof f);
        // 边界
        f[0][0] = 1;  // 空棋盘一种方案 其他 f[0][i] = 0
        // 枚举每一列
        for (int i = 1; i <= m; i++) {
            // 枚举每一种状态 j
            for (int j = 0; j < 1 << n; j++) {
                // 遍历可以转换到 j 的状态 k
                for (auto k: state[j]) {
                    // 状态转移公式
                    f[i][j] += f[i-1][k];
                }
            }
        }

        cout << f[m][0] << endl;

    }

    return 0;
}

















