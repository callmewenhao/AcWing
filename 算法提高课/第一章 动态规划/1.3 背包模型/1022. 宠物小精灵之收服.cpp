/*

二维费用背包：精灵球数目+皮卡丘体力值，这里费用的维度可以颠倒
目标：小精灵数目

*/

#include <iostream>

using namespace std;

const int M = 510, N = 1010;

int n, m, k, f[M][N];

int main() {
    cin >> n >> m >> k;
    
    while (k--) {
        int a, b;
        cin >> a >> b;
        for (int i = m; i > b; i--) {
            // y 总的写法是 i = m-1; i >= b; i--
            // 对应答案就成了 f[m-1][n] 表示能够使用的体力值从m-1开始
            // 还是我们这种写法好一点
            for (int j = n; j >= a; j--) {
                f[i][j] = max(f[i][j], f[i-b][j-a] + 1);
            }
        }
    }
    
    // 做完再去找剩余最大体力值
    cout << f[m][n] << " ";
    int k = m;
    while (k > 0 && f[k][n] == f[m][n]) {
        k--;
    }
    cout << m - k;
    
    return 0;
}