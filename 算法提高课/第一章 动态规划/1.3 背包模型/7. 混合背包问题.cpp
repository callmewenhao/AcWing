#include <iostream>
#include <vector>

using namespace std;

const int M = 1010; 

int n, m;
int f[M];

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        if (s == 0) { // 完全背包
            for (int j = v; j <= m; j++) {
                f[j] = max(f[j], f[j-v] + w);
            }
        } else {
            if (s == -1) s = 1;  // 01 背包看成，数量是 1 的多重背包
            // 每得到一个物品，就用这个物品更新一下 dp 数组
            for (int k = 1; k <= s; k *= 2) {
                for (int j = m; j >= k*v; j--) {
                    f[j] = max(f[j], f[j-k*v] + k*w);
                }
                s -= k;
            }
            if (s) {
                for (int j = m; j >= s*v; j--) {
                    f[j] = max(f[j], f[j-s*v] + s*w);
                }
            }
        }
    }

    cout << f[m];

    return 0;
}




