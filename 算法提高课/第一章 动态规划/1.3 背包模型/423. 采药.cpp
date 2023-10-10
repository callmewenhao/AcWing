#include <iostream>

using namespace std;

const int N = 1010;

int n, m, f[N];

int main() {
    
    cin >> m >> n;
    
    for (int i = 0; i < n; i++) {
        int t, v;
        cin >> t >> v;
        for (int j = m; j >= t; j--) {
            f[j] = max(f[j], f[j - t] + v);
        }
    }
    
    cout << f[m];
    
    return 0;
}