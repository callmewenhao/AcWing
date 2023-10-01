/*
@File    : 4737.cpp
@Author  : wenhao
@Time    : 2023/6/23 18:11
@LC      : 
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int N[10], M[10];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        int rs, rh;
        cin >> rs >> rh;
        int r = (rh + rs) * (rh + rs);

        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            int d = x * x + y * y;
            if (d <= r) {
                N[cnt++] = d;
            }
        }
        n = cnt;
        sort(N, N + n);

        cin >> m;
        cnt = 0;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            int d = x * x + y * y;
            if (d <= r) {
                M[cnt++] = d;
            }
        }
        m = cnt;
        sort(M, M + m);

        // output ans
        if (m == 0) {
            cout << "Case #" << cases << ": " << n << " " << 0 << endl;
            continue;
        }
        if (n == 0) {
            cout << "Case #" << cases << ": " << 0 << " " << m << endl;
            continue;
        }
        if (N[0] == M[0]) {
            cout << "Case #" << cases << ": " << 1 << " " << 1 << endl;
            continue;
        }
        if (N[0] < M[0]) {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (N[i] <= M[0]) ans++;
            }
            cout << "Case #" << cases << ": " << ans << " " << 0 << endl;
            continue;
        }
        if (M[0] < N[0]) {
            int ans = 0;
            for (int i = 0; i < m; i++) {
                if (M[i] <= N[0]) ans++;
            }
            cout << "Case #" << cases << ": " << 0 << " " << ans << endl;
            continue;
        }
    }


}






