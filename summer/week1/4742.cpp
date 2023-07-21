/*
@File    : AcWing4742.cpp
@Author  : wenhao
@Time    : 2023/6/15 13:43
@LC      : 
*/
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

const int N = 200010, M = N * 2;

int idx;
int h[N], w[N], cache[N];
int e[M], ne[M];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int x) {
    if (cache[x])
        return cache[x];
    cache[x] = 1;
    for (int i = h[x]; ~i; i = ne[i]) {
        int y = e[i];
        if (w[x] > w[y]) {
            cache[x] += dfs(y);
        }
    }
    return cache[x];
}

int main() {
    // cin cout 加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> w[i];
        }

        idx = 0;
        for (int i = 0; i <= n; i++) {
            h[i] = -1;
        }
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            add(x, y), add(y, x);
        }

        int ans = 0;
        for (int i = 0; i <= n; i++) {
            cache[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dfs(i));
        }
        cout << "Case #" << k << ": " << ans << endl;
    }
    return 0;
}




