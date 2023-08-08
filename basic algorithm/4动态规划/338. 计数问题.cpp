#include <iostream>
#include <vector>

using namespace std;

// 计算数字
int get(vector<int>& num, int l, int r) {
    int res = 0;
    for (int i = l; i >= r; i--) {
        res = res * 10 + num[i];
    }
    return res;
}

// 计算 10 的幂
int power10(int x) {
    int res = 1;
    while (x--)
        res *= 10;
    return res;
}

// 统计 1 ~ n 之间 x 的个数
int count(int n, int x) {
    if (!n)
        return 0;

    // 把数字拆到 vector 中
    vector<int> num;
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();
    // 计算答案
    int res = 0;
    // 枚举位数
    // 注意当 x = 0 时，要从第 2 高位开始，故 -!x
    for (int i = n - 1 - !x; i >= 0; i--) {
        // 计算前面的值
        if (i < n - 1) {
            res += get(num, n-1, i+1) * power10(i);
            if (!x) res -= power10(i);
        }
        // 计算后面的值
        if (num[i] == x)
            res += get(num, i - 1, 0) + 1;
        else if (num[i] > x)
            res += power10(i);
    }
    return res;
}

int main() {
    int a, b;
    // 回答每个询问
    while (cin >> a >> b, a || b) {
        if (a > b)
            swap(a, b);
        for (int i = 0; i < 10; i++) {
            cout << count(b, i) - count(a - 1, i) << " ";
        }
        cout << endl;
    }

    return 0;
}
