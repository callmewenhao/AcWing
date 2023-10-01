#include <iostream>
#include <algorithm>
#include <utility>

/*
1. 将所有区间按左端点从小到大排序
2. 从前往后依次枚举每个区间，在所有能覆盖 start 的区间中，选择右端点最大的区间，然后将 start 更新成右端点的最大值
3. 如果能够覆盖的话，start 最终的值将大于等于 end
*/

using namespace std;

const int N = 1e5+7;

int n, s, t;
pair<int, int> intervals[N];

int main() {
    // 读入数据
    cin >> s >> t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    // 排序
    sort(intervals, intervals + n);

    // 贪心
    int res = 0;
    bool success = false;
    for (int i = 0; i < n; i++) {
        int j = i, r = -2e9;
        while (j < n && intervals[j].first <= s) {
            r = max(r, intervals[j].second);
            j++;
        }

        if (r < s) {
            res = -1;
            break;
        }

        res++;
        if (r >= t) {
            success = true;
            break;
        }

        s = r;
        i = j - 1;  // 因为 i 还要++，所以等于 j-1
    }
    
    // 无解
    if (!success) res = -1;
    // 输出答案
    cout << res << endl;

    return 0;
}














