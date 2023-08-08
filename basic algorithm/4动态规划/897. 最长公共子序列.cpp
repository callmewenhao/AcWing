#include <iostream>

using namespace std;

const int N = 1007;

int n, m, f[N][N];
char a[N], b[N];

// 递推
int main() {

    cin >> n >> m;
    cin >> a+1 >> b+1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }

    cout << f[n][m] << endl;

    return 0;
}


// 记搜
/*
int cache[N][N];

int n, m;
char a[N], b[N];

int dfs(int i, int j) {
    if (i == 0 || j == 0) return 0;
    if (cache[i][j] != -1) return cache[i][j];

    int res = 0;
    if (a[i] == b[j]) res = dfs(i-1, j-1) + 1;
    else res = max(dfs(i-1, j), dfs(i, j-1));
    return cache[i][j] = res;
}


int main() {

    cin >> n >> m;
    cin >> a+1 >> b+1;

    // 初始化 cache
    for (int i = 0; i <= n; i++) {
        fill(cache[i], cache[i] + m + 1, -1);
    }

    // 记搜
    int res = dfs(n, m);

    cout << res << endl;

    return 0;
}
*/








