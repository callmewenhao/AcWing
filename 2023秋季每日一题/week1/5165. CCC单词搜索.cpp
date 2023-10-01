#include <iostream>
#include <string.h>

using namespace std;

const int N = 110;

int n, m, len_w;
char w[10], grid[N][N];
bool vis[N][N];

const int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int dy[8] = {0, 0, -1, 1, -1, 1, 1, -1};

/**
 * x
 * y
 * i
 * is_turn 是否转过弯 
 * is_direct 是否是水平或者竖直的
*/
int dfs(int x, int y, int i, bool is_turn, int direct) {
    if (i == len_w - 1 && grid[x][y] == w[i])
        return 1;
    if (grid[x][y] != w[i]) return 0;

    // cout << "dfs: " << x << " " << y << endl; 

    int res = 0;
    // 上下左右
    if (direct < 4) {
        if (is_turn) {
            int n_x = x + dx[direct], n_y = y + dy[direct];
            if (0 <= n_x && 0 <= n_y && n_x < n && n_y < m && !vis[n_x][n_y]) {
                vis[n_x][n_y] = true; 
                res += dfs(n_x, n_y, i+1, true, direct);
                vis[n_x][n_y] = false;
            }  
        } else {
            for (int j = 0; j < 4; j++) {
                int n_x = x + dx[j], n_y = y + dy[j];
                if (0 <= n_x && 0 <= n_y && n_x < n && n_y < m && !vis[n_x][n_y]) {
                    vis[n_x][n_y] = true; 
                    res += dfs(n_x, n_y, i+1, j != direct, j);
                    vis[n_x][n_y] = false;
                }
            } 
        }
    } else { // 其余四个斜着的方向
        if (is_turn) {
            int n_x = x + dx[direct], n_y = y + dy[direct];
            if (0 <= n_x && 0 <= n_y && n_x < n && n_y < m && !vis[n_x][n_y]) {
                vis[n_x][n_y] = true; 
                res += dfs(n_x, n_y, i+1, true, direct);
                vis[n_x][n_y] = false;
            }  
        } else {
            for (int j = 4; j < 8; j++) {
                int n_x = x + dx[j], n_y = y + dy[j];
                if (0 <= n_x && 0 <= n_y && n_x < n && n_y < m && !vis[n_x][n_y]) {
                    vis[n_x][n_y] = true; 
                    res += dfs(n_x, n_y, i+1, j != direct, j);
                    vis[n_x][n_y] = false;
                }
            } 
        }
    }
    return res;
}

int main() {

    cin >> w;
    len_w = strlen(w);
    // cout << w << endl;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        cin >> grid[i][j];
        // cout << "grid " << i << " " << grid[i] << endl; 
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != w[0]) continue;

            memset(vis, 0, sizeof vis);
            vis[i][j] = true;

            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int n_x = i + dx[k], n_y = j + dy[k];
                if (0 <= n_x && 0 <= n_y && n_x < n && n_y < m && !vis[n_x][n_y]) {
                    vis[n_x][n_y] = true;
                    cnt += dfs(n_x, n_y, 1, false, k);
                    vis[n_x][n_y] = false;
                }
                    
            }
            for (int k = 4; k < 8; k++) {
                int n_x = i + dx[k], n_y = j + dy[k];
                if (0 <= n_x && 0 <= n_y && n_x < n && n_y < m && !vis[n_x][n_y]) {
                    vis[n_x][n_y] = true;
                    cnt += dfs(n_x, n_y, 1, false, k);
                    vis[n_x][n_y] = false;
                }  
            }
            res += cnt;
            vis[i][j] = false;
            // cout << i << " " << j << " " << cnt << endl;
        }
    }

    cout << res << endl;

    return 0;
}


