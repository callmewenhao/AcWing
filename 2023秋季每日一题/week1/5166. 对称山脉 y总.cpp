/*

暴力是 n^3 的时间复杂度

数据范围是 5000 只支持 n^2 的时间

考虑先枚举区间的中心点，再向外扩展长度，
比如：1, 3, 5, ... 和 2, 4, 6, ...

枚举区间的中心点的时间是 On 的，向外扩展的时间也是 On 的

总的时间复杂度就是 On^2 的

维护一个答案数组 f[N]，f[i] 表示长度为 i 的区间的最小不对称值

每扩展得到一个区间，就更新对应长度 i 的答案数组 f[i]

*/
#include <iostream>
#include <cstring>

using namespace std;

const int N = 5010;

int n, h[N], f[N];

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i]; 
    
    // 答案初始化为最大值
    memset(f, 0x3f, sizeof f);

    // 枚举中心点
    for (int i = 0; i < n; i++) {
        // 枚举奇数长度
        for (int l = i, r = i, s = 0; 0 <= l && r < n; l--, r++) {
            s += abs(h[r] - h[l]);
            // 更新最小值
            f[r-l+1] = min(f[r-l+1], s);
        } 
        // 枚举偶数长度
        for (int l = i, r = i + 1, s = 0; 0 <= l && r < n; l--, r++) {
            s += abs(h[r] - h[l]);
            // 更新最小值
            f[r-l+1] = min(f[r-l+1], s);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << f[i] << " ";
    }

    return 0;
}



