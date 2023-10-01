#include <iostream>
#include <algorithm>


using namespace std;
using LL = long long;

const int N = 1e5+7;

int n;
int a[N];

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    LL res = 0;
    // 两两分组 求和
    for (int i = 0; i < n / 2; i++) {
        res += a[n-1-i] - a[i];
    }

    cout << res << endl;

    return 0;
}



