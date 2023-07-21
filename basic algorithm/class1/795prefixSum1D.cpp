/**
 * 一维前缀和
*/

#include <iostream>

using namespace std;

const int N = 1e5+7;
int a[N], s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << s[r]-s[l-1] << endl;
    }

    return 0;
}