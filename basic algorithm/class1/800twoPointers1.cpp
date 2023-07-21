/**
 * 相向双指针 利用单调性
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 7;
int A[N], B[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    // 相向双指针 利用单调性
    for (int i = 0, j = m - 1; i < n; i++) {
        while (A[i] + B[j] > x) {
            j--;
        }
        if (A[i] + B[j] == x) {
            cout << i << " " << j << endl;
            break;
        }
    }
    return 0;
}
