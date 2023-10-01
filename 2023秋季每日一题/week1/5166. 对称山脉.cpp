/*

# 前缀和 但是斜着🤗

刚开始写了一个暴力：

- 枚举区间长度 n
    - 枚举区间端点 n
        - 计算区间内元素差的绝对值之和 n/2

TLE 😣😣，毕竟数据范围是 5000

考虑优化最内层 for 循环，也就是快速的计算出区间内元素差的绝对值之和

一开始的想法是把 abs(h[i] - h[j]) 提前算出来，然后可以优化一个 abs 的时间，
这需要一个二维数组 s[N][N] 存储，s[i][j] 存 abs(h[i] - h[j])

考虑能否继续优化？可否把最内层 for 循环优化成 O1 的时间复杂度？

区间 [2, 8] 的元素差的绝对值之和是：sum[2, 8] = s[2][8] + s[3][7] + s[4][6] + s[5][5]

而 s[2][8] s[3][7] s[4][6] s[5][5] 在 s[N][N] 是连续的（斜着），那就可以使用前缀和提前计算出来

举一反三，对于任何一个区间 [i, j] 都可以通过前缀和计算😁

这样就是可以 O1 的计算某个区间的不对称值了hhhh😊

*/
#include <iostream>

using namespace std;

const int N = 5010;

int n, h[N], s[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    
    // 预处理 前缀和
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            s[i][j] = abs(h[i] - h[j]);
        }
    }
    for (int i = 2; i < n; i++) {
        // 主对角线1
        for (int x = i, y = i; 1 <= x && y <= n; x--, y++) {
            s[x][y] += s[x+1][y-1];
        }
        // 主对角线2
        for (int x = i - 1, y = i; 1 <= x && y <= n; x--, y++) {
            s[x][y] += s[x+1][y-1];
        }
    }
    
    // 枚举区间
    for (int l = 1; l <= n; l++) {
        int res = 1e9;
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1, d = (j-i) / 2;
            res = min(res, s[i][j] - s[i+d+1][j-d-1]);
        }
        cout << res << " ";
    }
    cout << endl;
    
    return 0;
}












