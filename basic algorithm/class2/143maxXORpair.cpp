/**
 * 最大异或对
 *
 * 把数字的二进制形式看成是字符串
 *
 * 如果要使得两个数字的异或值最大
 * 则可以贪心的从高位匹配到低位
 * 并尽量找到那些与当前字符不同的字符集合
 * 
 * 注意节点的个数最多是 30 * 1e5 级别的
 * 
 */
#include <iostream>

using namespace std;

const int N = 1e5 + 7, M = 31 * N;  

int son[M][2], a[N], idx;

// 把数字插入 trie
void insert(int x) {
    int p = 0;
    for (int i = 30; ~i; i--) {  // 高位到低位遍历
        int& s = son[p][(x >> i) & 1];
        if (!s)
            s = ++idx;
        p = s;
    }
}

// 针对每一个数字 找到对应的最大异或值
int search(int x) {
    int res = 0, p = 0;
    for (int i = 30; ~i; i--) {
        int s = (x >> i) & 1;
        if (son[p][!s]) {
            res += 1 << i;
            p = son[p][!s];
        } else
            p = son[p][s];
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        insert(a[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, search(a[i]));
    }

    cout << ans << endl;

    return 0;
}