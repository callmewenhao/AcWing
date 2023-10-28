#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110, M = 25010;

int t, n, a[N];
bool f[M];

int main() {

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);  // 排序

        int m = a[n-1];  // 背包最大值
        int res = 0;  // 不可去掉的数
        memset(f, false, sizeof f);  // 每一轮重新初始化 f
        f[0] = true;  // f[0][0] 是 true
        for (int i = 0; i < n; i++) {
            if (!f[a[i]]) res++;  // 不能被表示的数，不可去掉的数
            for (int j = a[i]; j <= m; j++) {  // 用这个货币去更新后面的背包容量的组成情况
                f[j] = f[j] || f[j - a[i]];
            }
        }
        cout << res << endl;
    }
    return 0;
}




