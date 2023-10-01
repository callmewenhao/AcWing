/*
数学解法

题目是求方程 ax+by=n 解的个数

使用扩展欧几里得算法可以求解上述方程的解以及解的个数

这一题 a 和 b 都是定值 4 5，相对容易

- 先找一个特解：x0 = -n, y0 = n

- 通解就是 x = x0 + 5k, y = y0 - 4k

- 又因为集合数大于等于 0，那可以求出 k 的取值范围

- x >= 0 -> x0 + 5k >= 0 -> 5k >= -n -> k >= ceil(n/5)  大于等于取上取整

- 同理 y >= 0 -> k <= floor(n/4) 小于等于取下取整

*/

#include <iostream>

using namespace std;

int n;

int main() {

    cin >> n;
    cout << n/4 - (n+4)/5 + 1 << endl;

    return 0;
}