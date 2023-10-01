/*
@File    : 4736.cpp
@Author  : wenhao
@Time    : 2023/6/20 13:24
@LC      : 
*/
#include <iostream>

using namespace std;


int main() {
    // cin cout 加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        int M, N, P;
        cin >> M >> N >> P;
        int S[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> S[i][j];
            }
        }
        int ans = 0;
        for (int j = 0; j < N; j++) {
            int mx = 0;
            for (int i = 0; i < M; i++) {
                if (S[mx][j] < S[i][j]) {
                    mx = i;
                }
            }
            ans += S[mx][j] - S[P-1][j];
        }
        cout << "Case #" << cases << ": " << ans << endl;
    }
}












