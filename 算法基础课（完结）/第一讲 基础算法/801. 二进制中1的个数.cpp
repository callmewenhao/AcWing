/**
 * lowbit(x) = x & (-x)
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 7;
int a[N];

int lowbit(int x) {
    return x & (-x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int x = a[i], cnt = 0;
        while (x) {
            cnt++;
            x = x - lowbit(x);
        }
        cout << cnt << " ";
    }
    cout << endl;

    return 0;
}
