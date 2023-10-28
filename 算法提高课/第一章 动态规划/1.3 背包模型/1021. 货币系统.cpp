#include <iostream>

using namespace std;

const int N = 16, M = 3010;

int n, m;
long long f[M];

int main() {

    cin >> n >> m;
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        for (int j = v; j <= m; j++) { 
            f[j] += f[j-v];
        }
    }

    cout << f[m]; 

    return 0;
}


