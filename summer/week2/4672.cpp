/*
@File    : 4672.cpp
@Author  : wenhao
@Time    : 2023/6/23 22:08
@LC      : 
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

const int N = 1010;
string C[N];
int D[N], U[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> C[i] >> D[i] >> U[i];
        }
        //
        int s1[n], s2[n];
        iota(s1, s1+n, 0);
        sort(s1, s1+n, [&](int a, int b){
            return C[a] < C[b] || C[a] == C[b] && U[a] < U[b];
        });
        iota(s2, s2+n, 0);
        sort(s2, s2+n, [&](int a, int b){
            return D[a] < D[b] || D[a] == D[b] && U[a] < U[b];
        });
        //
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) ans++;
        }
        cout << "Case #" << cases << ": " << ans << endl;
    }
    return 0;
}