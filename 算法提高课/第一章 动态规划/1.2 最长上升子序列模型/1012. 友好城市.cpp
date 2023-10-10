#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using PII = pair<int, int>;

const int N = 5010;

int n;
PII a[N];
int f[N];

int main() {

    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a+n);

    int res = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j].second < a[i].second) f[i] = max(f[i], f[j]+1);
        }
        res = max(res, f[i]);
    }

    cout << res;

    return 0;
}