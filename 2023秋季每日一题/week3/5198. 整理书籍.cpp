#include <iostream>
#include <string>

using namespace std;

const int N = 1e5+7;

int a[N], b[N], cnt[3], e[3][3];

int main() {
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'L') a[i] = 0;
        else if (c == 'M') a[i] = 1;
        else a[i] = 2;

        cnt[a[i]]++;
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    for (int i = 0, k = 0; i < 3; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            b[k++] = i;
        }
    }

    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;

    // 建图
    for (int i = 0; i < n; i++) {
        e[a[i]][b[i]]++;
    }

    int m = 0;
    // 自环
    for (int i = 0; i < 3; i++) {
        m += e[i][i];
    }

    // 小环
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 3; j++) {
            int t = min(e[i][j], e[j][i]);
            m += t;
            e[i][j] -= t, e[j][i] -= t;
        }
    }
    // 大环
    m += e[0][1] + e[1][0];

    cout << n - m << endl;

    return 0;
}










