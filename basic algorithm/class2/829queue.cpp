/**
 * 模拟队列
 * 
 * q[n] 队列
 * 
 * hh 头  弹出元素 hh++
 * 
 * tt 尾  插入元素x q[++tt] = x
 * 
 * 空  hh > tt 
 * 非空 hh <= tt
 * 
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int q[N], hh, tt = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int m;
    cin >> m;

    while (m--) {
        int x;
        string op;
        cin >> op;

        if (op == "push") {
            cin >> x;
            q[++tt] = x;
        } else if (op == "pop") {
            hh++;
        } else if (op == "empty") {
            if (hh > tt) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else if (op == "query") {
            cout << q[hh] << endl;
        }   
    }
    return 0;
}