#include <iostream>
#include <vector>

using namespace std;
using PII = pair<int, int>;

const int M = 32010, N = 70;

int n, m;
PII master[N];  // 主件
vector<PII> servant[N];  // 主件的从件
int f[M];  // dp 数组

int main() {

    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int v, p, q;
        cin >> v >> p >> q;
        if (!q) master[i] = {v, p * v};  // 主件
        else servant[q].push_back({v, p * v});  // 主件的从件
    }

    for (int i = 1; i <= n; i++) {
        // 一维 dp 数组注意反向遍历
        for (int j = m; j >= 0; j--) {
            if (master[i].first)  // 有主件
                for (int k = 0; k < 1 << servant[i].size(); k++) {  // 二进制枚举从件
                    int v = master[i].first, w = master[i].second;
                    for (int u = 0; u < servant[i].size(); u++) {
                        if (k >> u & 1) {
                            v += servant[i][u].first;
                            w += servant[i][u].second; 
                        }
                    } 
                    // 更新 dp 数组
                    if (j >= v) f[j] = max(f[j], f[j-v] + w);
                }
        }
    }

    cout << f[m];

    return 0;
}












