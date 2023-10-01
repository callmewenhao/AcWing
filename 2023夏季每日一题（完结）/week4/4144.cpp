#include <cstring>
#include <iostream>

using namespace std;

const int N = 5e5 + 7;
char a[N];
int suf[N];

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        int n;
        cin >> n >> a + 1;  // 从 a + 1 开始存
        // 后缀
        suf[n + 1] = 2 * N;  // 注意 这里至少是 2 * N！举例最极端的情况
        for (int i = n; i >= 1; i--) {
            if (a[i] == '1')
                suf[i] = i;
            else
                suf[i] = suf[i + 1];
        }

        // 前缀
        long long ans = 0; //  答案使用 long long
        int pre = -2 * N;
        for (int i = 1; i <= n; i++) {
            if (a[i] == '1')
                pre = i;
            ans += min(i - pre, suf[i] - i);
        }
        cout << "Case #" << cases << ": " << ans << endl;
    }
    return 0;
}
