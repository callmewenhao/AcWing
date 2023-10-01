/**
 * 双指针 滑窗
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 7;
int a[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 双指针
    int ans;
    for (int l = 0, r = 0; r < n; r++) {
        cnt[a[r]]++;

        while (cnt[a[r]] > 1) {
            cnt[a[l]]--;
            l++;
        }
        ans = max(ans, r-l+1);
    }

    cout << ans << endl;
    return 0;
}
