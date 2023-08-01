/**
 * 这个题目并不是传统的 中国剩余定理
 * 因为 模数 不保证是质数
 *
 */

#include <algorithm>
#include <iostream>

using namespace std;

using LL = long long;

int exgcd(LL a, LL b, LL& x, LL& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {

    int n;
    cin >> n;

    bool has_ans = true;
    LL a1, m1;

    cin >> a1 >> m1;    
    // 两两合并方程 k1*a1+m1 = k2*a2+m2
    // 先求 k1 和 k2 的值
    // 计算合并后的方程系数
    // 答案就是合并所有方程之后的 m1 % a1 的值
    for (int i = 1; i < n; i++) {
        LL a2, m2;
        cin >> a2 >> m2;

        LL k1, k2;
        LL d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d) {  
            // 方程无解
            has_ans = false;
            break;
        }
        // 翻倍得到真正的 k1 和 k2 的值
        k1 = k1 * (m2 - m1) / d;  // 这样写 k1 = k1 / d * (m2 - m1) 会 wa
        

        // 计算新的方程系数
        LL t = a2 / d;
        k1 = (k1 % t + t) % t;
        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);
    }
    if (has_ans) {
        cout << (m1 % a1 + a1) % a1 << endl;
    } else cout << "-1" << endl; 

    return 0;
}
