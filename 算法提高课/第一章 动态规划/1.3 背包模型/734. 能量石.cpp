#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 10010;

struct {
    int s, e, l;
} a[N];

int t;
int n, m;
int f[M];

int main() {

    cin >> t;
    for (int u = 1; u <= t; u++) {
        cin >> n;
        m = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].s >> a[i].e >> a[i].l;
            m += a[i].s;
        }

        sort(a, a+n, [&](auto x, auto y){
            return x.s * y.l < x.l * y.s;
        });

        memset(f, -0x3f, sizeof f);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int s = a[i].s, e = a[i].e, l = a[i].l;
            for (int j = m; j >= s; j--) {
                f[j] = max(f[j], f[j-s] + e - (j-s)*l);
            }
        }

        int res = 0;
        for (int j = 0; j <= m; j++) {
            res = max(res, f[j]);
        }

        cout << "Case #" << u << ": " << res << endl;
    }



    return 0;
}






