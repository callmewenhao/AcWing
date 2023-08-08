#include <iostream>
#include <cstring>

using namespace std;

const int N  = 307;
const int dxy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int r, c;
int h[N][N];  // 高度数组
int f[N][N];  // 记搜数组

// 记搜
// y总使用 & 的写法很清爽 👍
int dfs(int i, int j) {
    int & v = f[i][j];
    if (v != -1) return v;

    v = 1;
    for (auto d: dxy) {
        int x = i + d[0], y = j + d[1];
        if (1 <= x && 1 <= y && x <= r && y <= c && h[x][y] < h[i][j]) {
            v = max(v, dfs(x, y) + 1);
        }
    }
    // 更新答案
    return v;
}

int main() {

    cin >> r >> c;
    // 读入高度
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> h[i][j];
        }
    }

    // 初始化 f
    memset(f, -1, sizeof f);

    // 多源 dfs
    int res = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            res = max(res, dfs(i, j));
        }
    }

    cout << res << endl;

    return 0;
}






