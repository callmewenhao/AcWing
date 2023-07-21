/*
@File    : 4633.cpp
@Author  : wenhao
@Time    : 2023/6/23 22:29
@LC      : 
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int R[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> R[i];
        }
        // 二分
        int sortedR[n];
        copy(R, R + n, sortedR);
        sort(sortedR, sortedR + n);

        int ans[n];
        for (int i = 0; i < n; i++) {
            int x = R[i];
            auto idx = upper_bound(sortedR, sortedR + n, 2*x) - sortedR - 1;
            if (idx == 0) {
                ans[i] = -1;
            } else if (sortedR[idx] == x) {
                ans[i] = sortedR[idx-1];
            } else {
                ans[i] = sortedR[idx];
            }
        }
        cout << "Case #" << cases << ": ";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}