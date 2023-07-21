/**
 * 单调栈
 *  
 * 每个数左边第一个比它小的数
 * 
*/

#include <iostream>

using namespace std;

const int N = 1e5+7;
int stk[N], tt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        while (tt && stk[tt] >= x) {
            tt--;
        }
        if (tt) cout << stk[tt] << " ";
        else cout << -1 << " ";
        stk[++tt] = x;
    }
    cout << endl;
    return 0;
}