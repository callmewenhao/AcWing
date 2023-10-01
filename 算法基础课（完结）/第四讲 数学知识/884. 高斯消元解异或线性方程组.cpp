/**
 * 高斯消元解异或线性方程组
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int a[N][N];

int gauss() {
    int r, c;
    for (r = c = 0; c < n; c++) {
        // 找到非零行
        int t = r;
        for (int i = r; i < n; i++) {
            if (a[i][c]) {
                t = i;
                break;
            }
        }
        // 判断找到的结果对不对
        if (!a[t][c]) continue;
        // 交换行
        for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);
        // 下面清零
        for (int i = r + 1; i < n; i++)
            if (a[i][c])
                for (int j = c; j <= n; j++)
                    a[i][j] ^= a[r][j];
        r++;
    }
    // 解的情况
    if (r < n) {
        for (int i = r; i < n; i++)
            //如果等式右边不是 0
            if (a[i][n]) return 2;
        return 1;
    }
    // 求解
    for (int i = n-1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            // xi ^= aij * xj
            a[i][n] ^= a[i][j] * a[j][n];


    return 0;
}

int main() {

    // 输入方程
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];
        
    // 高斯消元解异或方程
    int res = gauss();

    // 解的情况
    if (res == 0) {
        for (int i = 0; i < n; i++) cout << a[i][n] << endl;
    } else if (res == 1) 
        puts("Multiple sets of solutions");
    else
        puts("No solution");

    return 0;
}

