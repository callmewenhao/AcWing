/*
差分
*/

#include <iostream>
#include <cstring>

using namespace std;

int m, n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> m >> n >> k;
    
    int a[m+10][n+10];
    memset(a, 0, sizeof a);
    
    while (k--) {
        char op;
        int x;
        cin >> op >> x;
        if (op == 'R') {
            a[x][1] += 1;
            a[x+1][1] -= 1;
            a[x][n+1] -= 1;
            a[x+1][n+1] += 1;
        } else {
            a[1][x] += 1;
            a[1][x+1] -= 1;
            a[m+1][x] -= 1;
            a[m+1][x+1] += 1;
        }
    }
    
    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
            // cout << a[i][j] << " ";
            if (a[i][j] % 2) res++;
        }
        // cout << endl;
    }
    
    cout << res;
    
    return 0;
}