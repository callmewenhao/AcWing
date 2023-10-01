#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 107, M = 10007;

int n, m;
int s[N], f[M];

int sg(int x) {
    if (f[x] != -1) return f[x];

    unordered_set<int> S;
    for (int i = 0; i < m; i++) {
        // 能选这数
        if (x >= s[i]) {
            S.insert(sg(x - s[i]));
        }
    }
    // 返回 sg 值
    for (int i = 0; ; i++)
        if (!S.count(i)) 
            return f[x] = i;
}

int main() {
    // 初始化记搜数组
    memset(f, -1, sizeof f);

    cin >> m;
    for (int i = 0; i < m; i++) cin >> s[i];

    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        res ^= sg(h);
    }

    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}







