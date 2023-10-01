#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 107, M = 10007;

int n;
int f[M];

int sg(int x) {
    if (f[x] != -1) return f[x];

    unordered_set<int> S;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j <= i; j++) {
            S.insert(sg(i) ^ sg(j));
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



