#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

const int N = 1e5+7;

int n;
pair<int, int> intervals[N];

int main() {
    // 读入数据
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    // 排序
    sort(intervals, intervals + n);

    // 贪心计算
    int cnt = 0;
    for (int i = 0; i < n;) {
        int r = intervals[i].second;
        int j = i + 1;
        while (j < n && intervals[j].first <= r) {
            r = min(r, intervals[j].second);  // 维护最小的右边界
            j++;
        }
        cnt++;
        i = j;
    }

    cout << cnt << endl;

    return 0;
}












