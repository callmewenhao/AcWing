#include <iostream>

using namespace std;

const int N = 2007, mod = 1e9 + 7;

int c[N][N];

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
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