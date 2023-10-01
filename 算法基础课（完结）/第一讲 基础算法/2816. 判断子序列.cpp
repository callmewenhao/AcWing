/**
 * 同向双指针
*/

#include <iostream>

using namespace std;

const int N = 1e5  +7;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    // 思路和我想得不太一样 
    // 枚举 b 而不是 a
    // 遇到 a 中的元素就记录一下 最后看记录的个数
    int i = 0, j = 0; // 局部变量需要初始化
    while (i < n && j < m) {
        if(a[i] == b[j]) i++;
        j++;
    }
    if (i == n)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    return 0;
}




