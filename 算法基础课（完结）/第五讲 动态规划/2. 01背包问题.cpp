/**
 * 01背包 f[i][j] = max(f[i-1][j], f[i-1][j-v[i]]+w[i])
*/

#include <iostream>

using namespace std;

const int N = 1010;

// 二维
/*
int n, m;
int v[N], w[N], f[N][N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    // 初始化 f[0][0] = 0;
    for (int i = 1;  i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i-1][j];
            if (j >= v[i]) 
                f[i][j] = max(f[i][j],f[i-1][j-v[i]] + w[i]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
*/

// 一维
int n, m;
int w[N], v[N], f[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    // 初始化 f[0] = 0;
    for (int i = 1;  i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}




