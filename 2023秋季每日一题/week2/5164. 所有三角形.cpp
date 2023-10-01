#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5+7;

int n, a[2][N];

int main() {

    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int res = 0;
    for (int j = 1; j <= n; j ++) {
        if (a[0][j]) {
            res += 3;
            if (a[0][j-1]) res -= 2;
        }
        
        if (a[1][j]) {
            res += 3;
            if (a[1][j-1]) res -= 2;
        }
        if (a[0][j] && a[1][j] && (j % 2 == 1)) res -= 2;
    }

    cout << res << endl;

    return 0;
}
