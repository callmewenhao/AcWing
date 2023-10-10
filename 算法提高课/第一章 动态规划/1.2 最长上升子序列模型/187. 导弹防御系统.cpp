#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;

int n;
int a[N];
int up[N], down[N];
int ans;

void dfs(int u, int su, int sd) {
    if (ans <= su + sd) return;
    if (u == n) {
        ans = su + sd;
        return ;
    }

    int k = 0;
    while (k < su && up[k] < a[u]) k++;
    int t = up[k];
    up[k] = a[u];
    if (k < su) dfs(u+1, su, sd);
    else dfs(u+1, su+1, sd);
    up[k] = t; // 注意恢复现场

    k = 0;
    while (k < sd && down[k] >= a[u]) k++;
    t = down[k];
    down[k] = a[u];
    if (k < sd) dfs(u+1, su, sd);
    else dfs(u+1, su, sd+1); 
    down[k] = t; // 恢复现场
}

int main() {
    
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) cin >> a[i];

        ans = n;
        dfs(0, 0, 0);
        cout << ans << endl;
    }

    return 0;
}