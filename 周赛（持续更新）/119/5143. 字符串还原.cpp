/*

暴力

枚举每一个点，再枚举这个点上的环，判断枚举的环是不是同一种颜色

(n*m)*(n*m)*(n+m) = n^2 * n^2 * n = 2*n^5

前缀和优化最后一个 n

*/

#include <iostream>

using namespace std;

const int N = 60;
int n ,m, a[N][N], s[N][N][26]; 

int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            int c = x-'A';
            a[i][j] = c;
            s[i][j][c] = 1 + s[i][j][c] + s[i][j][c] - s[i-1][j-1][c];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool find = false;
            for (int x = i+1; x <= n; x++) {
                for (int y = j+1; y <= m; y++) {
                    int c = a[i][j];
                    if (c != a[x][y]) continue;
                    int c1 = s[x][y][c] - s[x][j-1][c] - s[i-1][y][c] + s[i-1][j-1][c];
                    
                    int ni = i+1, nj = j+1, nx = x-1, ny = y-1;
                    int c2 = 0;
                    if (ni <= nx && nj <= ny)  {
                        c2 = s[nx][ny][c] - s[nx][nj-1][c] - s[ni-1][ny][c] + s[ni-1][nj-1][c];
                    }
                    if ((c1 - c2) == 2*(y-j+1 + x-i-1)) {
                        cout << "Yes";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No";

    return 0;
}








