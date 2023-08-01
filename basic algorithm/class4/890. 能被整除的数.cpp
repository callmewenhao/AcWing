#include <iostream>

using namespace std;

using LL = long long;

const int M = 20;
int p[M];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) cin >> p[i];

    int res = 0;
    // 先枚举状态
    for (int i = 1; i < 1 << m; i++) {
        int t = 1, cnt = 0;
        // 查看是哪些集合
        for (int j = 0; j < m; j++) {
            if ((i >> j & 1) == 0) {  // == 的优先级比 & 高
                continue;
            }
            
            if ((LL) t * p[j] > n) {
                t = -1;
                break;
            }
            
            cnt++;
            t *= p[j];
        }
        if (t != -1) {
            res += (cnt % 2 ? 1 : -1) * n / t;
        }
    }
    // 时间复杂度确实是 O(2^m*m)

    cout << res << endl;

    return 0;
}
