#include <iostream>
#include <cstring>

using namespace std;

const int N = 50010, M = N;

int n;
int h[N], e[M], ne[M], idx;
int s[N];
bool st[N];
int ans;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int x) {
    st[x] = true;
    
    int dist = 0;
    int d1 = 0, d2 = 0;
    for (int i = h[x]; ~i; i = ne[i]) {
        int y = e[i];
        if (!st[y]) {
            int d = dfs(y);
            dist = max(dist, d);
            if (d >= d1) {
                d2 = d1, d1 = d;
            } else if (d > d2) {
                d2 = d;
            }
        }
    }
    ans = max(ans, d1 + d2);
    return dist + 1;
}

int main() {

    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n / i; j++) {
            s[i * j] += i;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (s[i] < i) add(s[i], i);
    }

    for (int i = 1; i <= n; i++) {
        if (!st[i]) dfs(i);    
    }

    cout << ans;

    return 0;
}






