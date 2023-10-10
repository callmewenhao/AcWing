#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N], g[N];

int main() {

    while (cin >> a[n]) n++;

    int res = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] >= a[i]) f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    cout << res << endl;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int t = 0;
        while (t < cnt && g[t] < a[i]) t++;
        g[t] = a[i];
        cnt = max(cnt, t + 1); 
    }

    cout << cnt << endl;

    return 0;
}










