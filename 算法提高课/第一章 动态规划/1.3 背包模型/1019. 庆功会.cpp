#include <iostream>

using namespace std;

const int N = 6010;

int n, m, f[N]; 

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k * v <= j && k <= s; k++) {
                f[j] = max(f[j], f[j-k*v] + k*w);
            }
        }
    }

    cout << f[m];

    return 0;
}