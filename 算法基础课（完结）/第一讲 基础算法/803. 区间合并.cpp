/**
 * 区间合并
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 7;
vector<pair<int, int>> intervals;

// 计算合并完成后的区间个数
int merge(vector<pair<int, int>>& intervals) {
    int cnt = 0;
    int start = -2e9, end = -2e9;
    for (auto [l, r] : intervals) {
        if (end < l) {
            if (start != -2e9) cnt++;
            start = l, end = r;
        } else {
            end = max(end, r);
        }
    }
    if (start != -2e9) cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals.emplace_back(l, r);
    }
    sort(intervals.begin(), intervals.end());
    cout << merge(intervals) << endl;

    return 0;
}
