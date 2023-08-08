#include <iostream>
#include <algorithm>

using namespace std;

const int N = 507, inf = 1e9; 

int n, f[N][N];

int main() {
    cin >> n;
    // 由于存在负数，需要把 f[N][N] 初始化为 -inf
    for (int i = 0;  i <= n; i++)
        std::fill(f[i], f[i] + n + 1, -inf);  // 注意要先读入 n
    // 读入数组
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> f[i][j];
        }
    }
    int res = -inf;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] += max(f[i-1][j-1], f[i-1][j]);
            if (i == n) res = max(res, f[i][j]);
        }
    }
    cout << res << endl;

}

