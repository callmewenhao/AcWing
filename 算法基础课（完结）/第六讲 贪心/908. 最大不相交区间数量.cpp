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

    // 贪心
    int cnt = 1, r = intervals[0].second;
    for (int i = 1; i < n; i++) {
        if (intervals[i].first <= r) {
            r = min(r, intervals[i].second);
        } else {
            cnt++;
            r = intervals[i].second;
        }
    }

    cout << cnt << endl;

    return 0;
}






