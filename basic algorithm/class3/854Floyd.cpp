/**
 * Floyd 算法
 * 
 * 多源最短路 本质是动态规划
 * 适用于任何图，不管有向无向，边权正负，但是最短路必须存在。（不能有个负环）
 * 
 * y总：Floyd 超简单 三重 for 循环
 * 
 * 点 i 到点 j 的距离 d[i][j]
 * 算法流程：
 *  for k from 1 to n:
 *      for i from 1 to n:
 *          for j from 1 to n:
 *              d[i][j] = min(d[i][j], d[i][k] + d[k][j])
 * 
 * 直接建立 邻接矩阵 存图
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 207, INF = 1e9;

int n, m, k;
int d[N][N];

// floyd 算法
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    
    cin >> n >> m >> k;
    // 初始化 邻接矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    // Floyd 算法
    floyd();

    // 查询
    while (k--) {
        int a, b;
        cin >> a >> b;
        if (d[a][b] > INF / 2) cout << "impossible" << endl;
        else cout << d[a][b] << endl;
    }

    return 0;
}




