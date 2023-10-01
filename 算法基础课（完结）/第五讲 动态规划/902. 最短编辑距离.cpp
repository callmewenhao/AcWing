#include <iostream>

using namespace std;

const int N = 1007;

int n, m;
char a[N], b[N];
int f[N][N];

int main() {

    cin >> n >> a+1;
    cin >> m >> b+1;

    // 初始化边界
    for (int i = 0; i <= n; i++) f[0][i] = i;
    for (int j = 0; j <= m; j++) f[j][0] = j;

    // 递推
    // 其实 a->b 和 b->a 是一样的
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // 取三种操作中的最小值
            f[i][j] = min(f[i-1][j-1] + int(b[i] != a[j]), min(f[i-1][j], f[i][j-1]) + 1);
        }
    }
    cout << f[m][n] << endl;

    return 0;
}


