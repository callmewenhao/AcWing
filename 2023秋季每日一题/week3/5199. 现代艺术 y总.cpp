/*
用两个数组存行列的改变次数
*/


#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e6+7;

int m, n, k, r[N], c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> m >> n >> k;
    
    char op;
    int x;
    while (k--) {
        cin >> op >> x;
        if (op == 'R') r[x]++;
        else c[x]++;
    }
    
    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int a = r[i] + c[j];
            if (a % 2) res++;
        }
    }
    
    cout << res;
    
    return 0;
}