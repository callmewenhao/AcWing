#include <cstring>
#include <iostream>

using namespace std;

const int N = 110, M = 7;

int n, m, L;
char w[M], g[N][N];
int res;

// 从正上方开始，顺时针走，脑海里有画面就行
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// d 表示方向
// cnt 表示是否转过弯
void dfs(int x, int y, int u, int d, bool cnt) {
    if (x < 0 || y < 0 || n <= x || m <= y || g[x][y] != w[u])
        return;
    if (u == L - 1)
        res++;
    else {
        dfs(x + dx[d], y + dy[d], u + 1, d, cnt);
        if (u && !cnt) {
            for (int i = 0; i < 2; i++) {
                // 位置不变 换个方向 表示转弯
                dfs(x, y, u, d ^ 2 ^ (i << 2), true);
            }
        }
    }
}

int main() {
    cin >> w;
    cin >> n >> m;
    L = strlen(w);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 8; d++) {
                // 不会死循环 不用记忆化
                dfs(i, j, 0, d, false);
            }
        }
    }

    cout << res << endl;

    return 0;
}
