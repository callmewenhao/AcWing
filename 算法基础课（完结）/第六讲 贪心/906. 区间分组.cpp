#include <iostream>
#include <algorithm>
#include <queue>

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
    // 优先队列
    priority_queue<int, vector<int>, greater<>> q;

    // 排序
    sort(intervals, intervals + n);

    // 贪心
    q.push(intervals[0].second);
    for (int i = 1; i < n; i++) {
        int l = intervals[i].first, r = intervals[i].second;
        // 放入同一组
        if (q.top() < l) {
            q.pop();
            q.push(r);
        } else {  // 不同组
            q.push(r);
        }
    }

    cout << q.size() << endl; 

    return 0;
}

