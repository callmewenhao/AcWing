#include <iostream>

using namespace std;

const int N = 30, M = 30010;

int n, m, f[M];

int main() {

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;
        w *= v;
        for (int j = m; j >= v; j--) {
            f[j] = max(f[j], f[j-v] + w);
        }
    }

    cout << f[m];

    return 0;
}





