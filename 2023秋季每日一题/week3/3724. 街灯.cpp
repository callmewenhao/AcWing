/*

题目其实是表达：覆盖 [0, n] 这 n + 1 个点还需要多少个灯

已经存在的灯会覆盖一个区间内的点 [x-k, x+k] 共 1 + 2 * k 个点

所以只需要贪心的把灯放在没有被覆盖的区间就好

比如：区间 [l1, r1] 与区间 [l2, r2]，满足 r1 < l2 - 1
这表示两个区间之间存在 l2 - r1 - 1 个点未覆盖

一盏灯可以覆盖 1 + 2*k 个点，则需要 (l2 - r1 - 1) / (1 + 2*k) 上取整个点

那么遍历所有的区间，如果当前区间和上一个区间满足 r1 < l2 - 1
就计算添加的灯数

如果最后一个区间的范围不包括 n 这个点，就说明后面还要再添加灯

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<pair<int, int>> a;

int main() {

    while (cin >> n >> m >> k) {
        a.clear();

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            a.push_back({x-k, x+k});
        }
        // 数据很弱，似乎是按顺序给的
        // sort(a.begin(), a.end());

        int res = 0, ed = 0;
        for (auto [l, r]: a) {
            if (ed < l - 1)
                res += (l - ed - 1 + 2 * k) / (2 * k + 1);
            ed = r;
        }
        if (ed < n) res += (n - ed + 2 * k) / (2 * k + 1);
        cout << res << endl;
    }

    return 0;
}
