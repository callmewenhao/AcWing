#include <iostream>

using namespace std;

const int N = 11, M = 16;

int n, m, w[N][M];
int f[N][M], way[N];

int main() {
    
    cin >> n >> m;
    // 存公司的机器分配收益
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
        }
    }
    
    // 分组背包
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i-1][j];
            for (int k = 1; k <= j; k++) {
                f[i][j] = max(f[i][j], f[i-1][j - k] + w[i][k]);
            }
        }
    }
    
    cout << f[n][m] << endl;
    
    // 倒着遍历一遍求出具体方案
    int j = m;
    for (int i = n; i; i--) {
        for (int k = 0; k <= j; k++) {
            if (f[i][j] == f[i-1][j-k] + w[i][k]) {
                way[i] = k;
                j -= k;
                break;
            }
        }
    }
    
    // 打印具体方案
    for (int i = 1; i <= n; i++) {
        cout << i << " " << way[i] << endl;
    }
    
    return 0;
}