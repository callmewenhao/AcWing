#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 10010;

int n, m;
int f[M];

int main() {
    cin >> n >> m;
    
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = m; j >= x; j--) {
            f[j] += f[j-x];
        }
    }
    
    cout << f[m];
    
    return 0;
}
