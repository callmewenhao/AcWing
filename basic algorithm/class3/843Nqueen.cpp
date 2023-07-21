/**
 * DFS
 * 
 * N 皇后问题
 *
 * 全排列写法
 * 枚举每一行应该选哪一列放置皇后
 *
 */

#include <iostream>

using namespace std;

const int N = 20;

int n;
char graph[N][N];
bool col[N], diag[N], udiag[N];  
// 注意 主对角线的编号 n - r + c 副对角线编号 r + c

// 全排列的写法
void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            puts(graph[i]);
        }
        puts("");
    }
    // 枚举选哪列
    for (int i = 0; i < n; i++) {
        if (!col[i] && !diag[u + i] && !udiag[n - u + i]) {
            graph[u][i] = 'Q';
            col[i] = diag[u + i] = udiag[n - u + i] = true;
            dfs(u + 1);
            // 恢复现场
            col[i] = diag[u + i] = udiag[n - u + i] = false;
            graph[u][i] = '.';
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}
