#include <iostream>
#include <queue>

using namespace std;

const int N = 2e5+7;

int n, w[N], h[N];

int main() {

    cin >> n;

    int sum_w = 0;
    priority_queue<int, vector<int>, less<int>> qu;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> h[i];
        sum_w += w[i];
        qu.push(h[i]);
    }

    // 计算答案
    for (int i = 1; i <= n; i++) {
        int res = sum_w - w[i];
        bool is_pop = false;
        if (qu.top() == h[i]) {
            qu.pop();
            is_pop = true;
        }
        res *= qu.top();
        cout << res << " ";
        // 恢复
        if (is_pop) qu.push(h[i]);
    }
    cout << endl;


    return 0;
}




