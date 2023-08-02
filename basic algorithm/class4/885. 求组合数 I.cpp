#include <iostream>

using namespace std;

const int N = 2007, mod = 1e9+7;

int c[N][N];

void init() {
    for (int i = 0; i < N; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }
}

int main() {
    int n;
    cin >> n;

    init();

    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << c[a][b] << endl;
    }

    return 0;
}