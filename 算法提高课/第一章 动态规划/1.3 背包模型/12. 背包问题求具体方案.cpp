#include <iostream>

using namespace std;

const int N = 1010;

int n, m, v[N], w[N];
int f[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    // 反着递推，方便找到字典序最小的具体方案
    for (int i = n; i > 0; i--) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i+1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i+1][j - v[i]] + w[i]);
        }
    }

    // 找方案
    int j = m;
    for (int i = 1; i <= n; i++) {
        if (j >= v[i] && f[i][j] == f[i+1][j-v[i]] + w[i]) {
            cout << i << " ";
            j -= v[i];
        }
    }
}





















