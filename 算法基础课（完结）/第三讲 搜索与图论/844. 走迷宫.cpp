/**
 * BFS
 * 
 * 走迷宫
 * 
 * 当所有边的权重一样时 可以使用 bfs 求最短路
 * 
 * 可以使用 C++ STL queue
 * 也可以使用数组模拟 queue
 * 时间差别不是很大
 * 
*/
#include <queue>
#include <iostream>

using namespace std;

const int N = 110;
const int ds[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
};

// 模拟 queue
pair<int, int> q[N * N];
int hh, tt = -1;

// 迷宫数据
int n, m;
int maze[N][N];

// 使用 bfs 求出最短路
// 题目保证一定能找到
int bfs() {
    // bfs
    int cnt = 0;
    q[++tt] = {0, 0};  // push
    maze[0][0] = 1;  // 放入 qu 就要改！

    while (hh <= tt) {
        int l = tt - hh + 1;
        for (int i = 0; i < l; i++) {
            int x = q[hh].first, y = q[hh].second;
            hh++;  // pop
            
            // 终点
            if (x == n - 1 && y == m - 1) {
                return cnt;
            }

            for (auto &d: ds) {
                int nx = x + d[0], ny = y + d[1];
                if (0 <= nx && 0 <= ny && nx < n && ny < m && !maze[nx][ny]) {
                    q[++tt] = {nx, ny};  // push
                    maze[nx][ny] = 1;
                }
            }
        }
        cnt++;
    }
    return -1;
}

// 使用 stl 中的 queue
int bfs_stl() {
    // bfs
    int cnt = 0;
    queue<pair<int, int>> qu;
    qu.emplace(0, 0);
    maze[0][0] = 1;  // 放入 qu 就要改！

    while (!qu.empty()) {
        int l = qu.size();
        for (int i = 0; i < l; i++) {
            auto [x, y] = qu.front();
            qu.pop();
            
            // 终点
            if (x == n - 1 && y == m - 1) {
                return cnt;
            }

            for (auto &d: ds) {
                int nx = x + d[0], ny = y + d[1];
                if (0 <= nx && 0 <= ny && nx < n && ny < m && !maze[nx][ny]) {
                    qu.emplace(nx, ny);
                    maze[nx][ny] = 1;
                }
            }
        }
        cnt++;
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j< m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    printf("%d\n", bfs_stl());
    return 0;
}


