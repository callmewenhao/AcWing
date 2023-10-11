#include <iostream>

using namespace std;

const int N = 1010;

int n, v[4] = {10, 20, 50, 100}, f[N];

int main() {

    cin >> n;

    f[0] = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = v[i]; j <= n; j++) {
            f[j] += f[j-v[i]];
        }
    }

    cout << f[m];

    return 0;
}
