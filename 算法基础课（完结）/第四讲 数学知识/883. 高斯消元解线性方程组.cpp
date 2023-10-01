/**
 * 高斯消元解线性方程组
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-6;  // 精度

int n;
double a[N][N];


// 返回值 
// 0：唯一解
// 1：无穷解
// 2：无解
int gauss() {
    int c, r;
    // 枚举每一列 c
    for (c = 0, r = 0; c < n; c++) {
        // 找到绝对值最大的行
        int t = r; // 从当前这一行开始向下找
        for (int i = r; i < n; i++)
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        // 如果找到的当前行列是 0 （小于精度）
        if (fabs(a[t][c]) < eps) continue;
        // 不是 0 就交换
        for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);  // 等号右侧的值也要交换
        // 将该行的的第 1 数变成 1 注意要从后向前运算，防止覆盖
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];
        // 把下面所有行的第 c 列消成 0
        for (int i = r + 1; i < n; i++) 
            // 如果已经是 0 了，就不用减了
            // 否则需要减去
            if (fabs(a[i][c]) > eps) 
                // 还是要从后向前运算，防止覆盖
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];
        r++;
    }
    // 解的情况
    if (r < n) {
        //判断是否无解
        for (int i = r; i < n; i++) {
            //如果等式右边不是 0
            if (fabs(a[i][n]) > eps) return 2;  // 无解
        }
        // 有无穷解
        return 1;
    }
    // 求解过程，消元
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) 
            a[i][n] -= a[i][j] * a[j][n];  // 答案存储在 a[i][n] 中
    }

    return 0;
}

int main() {
    // 读入方程组
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j <= n; j++) 
            cin >> a[i][j];

    // 进行高斯消元
    int t = gauss();

    // 解的情况
    if (t == 0) {
        for (int i = 0; i < n; i++) printf("%.2lf\n", a[i][n]);
    } else if (t == 1) 
        puts("Infinite group solutions");
    else
        puts("No solution");

    return 0;
}
