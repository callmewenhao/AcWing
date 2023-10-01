/*
@File    : 4738.cpp
@Author  : wenhao
@Time    : 2023/6/21 10:46
@LC      : 
*/
#include <iostream>

using namespace std;
using LL = long long;

const int N = 400005, INF = 1e9;
// 单调栈
int stk[N];
// 前缀和数组
LL A[N], B[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            A[i] = A[i - 1] + x;  // 前缀和
            B[i] = B[i - 1] + (n - i) * x; // (前缀和*等差数列)的前缀和
        }

        // 从右向左 一边单调栈一边枚举左端点
        LL ans = 0;
        int top = 0;
        A[n + 1] = -INF;
        stk[++top] = n + 1; // 添加哨兵
        for (int i = n; i >= 0; i--) {
            while (A[stk[top]] >= A[i]) {
                top--;
            }
            int j = stk[top];
            stk[++top] = i;
            ans += B[j - 1] - B[i] - (n - j) * (A[j - 1] - A[i]);
        }
        cout << "Case #" << cases << ": " << ans << endl;
    }
    return 0;
}




