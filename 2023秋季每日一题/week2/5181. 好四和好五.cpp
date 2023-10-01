/*
这个题目还行
能看出来是完全背包

只可惜背包好久没写有些生疏
*/

#include <iostream>

using namespace std;

const int N = 1e6+7;

int n, a[3] = {0, 4, 5}, f[N];

int main() {

    cin >> n;
    f[0] = 1;
    for (int i = 1; i < 3; i++) {
        for (int j = a[i]; j <= n; j++) {
            f[j] = f[j] + f[j-a[i]];
        }
    }

    cout << f[n] << endl;

    return 0;
}