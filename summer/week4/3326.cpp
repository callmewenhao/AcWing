#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e3+7;
long long c[N][N];

int main() {
    // 这个题目用 速读 快一点
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;

    for (int cases = 1; cases <= T; cases++) {
        int n;
        cin >> n;

        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> c[i][j];
                c[i][j] += c[i-1][j-1];
                if (i == n || j == n) 
                    ans = max(ans, c[i][j]);
            }
        }
        cout << "Case #" << cases << ": " << ans << endl;
    }

    return 0;
}