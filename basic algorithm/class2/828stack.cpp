/**
 * 模拟栈
 * stk[N] 表示栈
 * tt 表示栈顶指针
 * 插入元素 stk[++tt] = x
 * 弹出 tt--
 * 判空 tt == 0
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 7;
int stk[N], tt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int m;
    cin >> m; 

    string op;
    while (m--) {
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            stk[++tt] = x;
        } else if (op == "pop") {
            tt--;
        } else if (op == "empty") {
            if (tt == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else if (op == "query") {
            cout << stk[tt] << endl;
        }
    }
    return 0;
}