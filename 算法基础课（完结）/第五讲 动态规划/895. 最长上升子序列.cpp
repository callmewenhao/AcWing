#include <iostream>

using namespace std;

const int N = 1007;

int n, a[N], f[N];  // f[i] 表示以 i 结尾的最长上升子序列

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i]; 

    int res = 0;
    for (int i = 1;  i <= n; i++) {
        int mx = 0;
        for (int j = 1; j < i; j++) {
            // 严格单调递增
            if (a[i] > a[j]) mx = max(mx, f[j]);
        }
        f[i] = 1 + mx;
        res = max(res, f[i]);
    }

    cout << res << endl;

    return 0;
}


