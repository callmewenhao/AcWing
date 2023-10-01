/*
这个题目先看数据范围：

区域大小 N：2<= N <=5*10^5,
树的个数 T：1 <= T <= 100,
保证：T < N^2

因为树的个数小于 100，所以可以枚举树：

- 枚举四棵树，然后计算围成的区域内最大的矩形面积

- 时间复杂度是 O(T^4) 可以接受

优化：分析最大的矩形满足哪些性质

- 只有一个方向受限制，比如：在水平方向受限制，那么在竖直方向上可以选的长度满足 >= 水平方向距离
这就意味着可以枚举受限制的方向

- 这样只需枚举水平方向上的左右两棵树，然后再看竖直方向是否满足要求

- 如果我们把树的坐标按照水平位置排序，然后从左向右枚举，
那么可以维护一个上下的边界从而 O1 的判断竖直方向上的长度是否满足要求

- 在枚举的时候，选定左边一棵树，然后枚举右边树的选择，注意需要跳过左边同坐标的树

- 另外，边界的限制可以设置四个角为哨兵。提供边界限制

*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define x first
#define y second

const int N = 110;

int n, m;
pair<int, int> tr[N];

int solve() {
    sort(tr, tr+m);

    int res = 0;
    // 枚举每一棵树
    for (int i = 0; i < m; i++) {
        // 上下两个边界
        int up = n+1, down = 0;
        // 枚举树 i 后面的树 同一行要跳过
        for (int j = i+1; j < m; j++) {
            if (tr[j].x == tr[i].x) continue;
            if (tr[j].x - tr[i].x > up - down) break;
            res = max(res, tr[j].x - tr[i].x - 1);
            if (tr[j].y >= tr[i].y) 
                up = min(up, tr[j].y);
            if (tr[j].y <= tr[i].y) 
                down = max(down, tr[j].y);
        }
    }
    return res;
}


int main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> tr[i].x >> tr[i].y;
    }
    tr[m++] = {0, 0};
    tr[m++] = {0, n+1};
    tr[m++] = {n+1, 0};
    tr[m++] = {n+1, n+1};

    int res = solve();
    for (int i = 0; i < m; i++) swap(tr[i].x, tr[i].y);
    res = max(res, solve());
    cout << res << endl;
    return 0;
}

