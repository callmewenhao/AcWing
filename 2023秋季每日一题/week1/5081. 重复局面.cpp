/**
 * 这题也可以使用 unordered_map 甚至比 tire 快
*/
#include <iostream>

using namespace std;

const int N = 1e5+7;

int son[N][128], cnt[N], idx;

// 插入新字符串
void insert(char* str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int c = str[i];
        if (!son[p][c]) son[p][c] = ++idx;
        p = son[p][c];
    }
    cnt[p]++;
}

// 这个字符串有几个
int query(char* str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int c = str[i];
        if (!son[p][c]) return 0;
        p = son[p][c];
    }
    return cnt[p];
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char str[70];
        for (int j = 0; j < 8; j++) {
            cin >> str + j * 8;
        }
        insert(str);
        cout << query(str) << endl;
    }

    return 0;
}

// a^p%d
int qmi(int a, int k, int p) {
    int res = 0;
    while (k) {
        if (k & 1) res = 1LL * res * a % p;
        k >>= 1;
        a = 1LL * a * a % p;
    }
    return res;
}