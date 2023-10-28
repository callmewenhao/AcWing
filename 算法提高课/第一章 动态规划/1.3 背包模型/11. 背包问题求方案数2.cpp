#include <iostream>
#include <cstring>

using namespace std;
const int N = 1010, MOD = 1e9+7;

int n, m;
int f[N], g[N];

int main() {
    cin >> n >> m;

    // 最多不超过 j 时的方案数初始化都为 1
    for (int j = 0; j <= m; j++) g[j] = 1;
    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            int maxv = max(f[j], f[j-v] + w);
            int cnt = 0;
            if (maxv == f[j]) cnt = (cnt + g[j]) % MOD;
            if (maxv == f[j-v] + w) cnt = (cnt + g[j-v]) % MOD;
            g[j] = cnt;
            f[j] = maxv;
        }
    }

    cout << g[m];
}






