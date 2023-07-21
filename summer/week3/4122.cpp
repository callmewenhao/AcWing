/*
@File    : 4122.cpp
@Author  : wenhao
@Time    : 2023/6/27 21:35
@LC      : 
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        string S, F;
        cin >> S;
        cin >> F;

        int ans = 0;
        for (auto si: S) {
            int res = 26; // 14=<res
            for (auto fi: F) {
                int d = min((si - fi + 26) % 26, (fi - si + 26) % 26);
                res = min(res, d);
            }
            ans += res;
        }
        cout << "Case #" << cases << ": " << ans << endl;
    }
    return 0;
}