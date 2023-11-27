#include <iostream>
#include <vector>

using namespace std;

const int N = 110, M = 1 << 10; 

int n, m, g[N];
vector<int> state;
vector<int> head[M];
int cnt[M];
int f[2][M][M];

bool check(int x) {
    for (int i = 0; i < m; i++) {
        if (x >> i & 1 && (x >> (i+1) & 1 || x >> (i+2) & 1))
            return false;
    }
    return true;
}

int pop_count(int x) {
    int res = 0;
    for (int i = 0; i < m; i++) {
        if (x >> i & 1) res++;
    }
    return res;
}

int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'H') g[i] |= 1 << j;
        }
    }

    for (int i = 0; i < 1 << m; i++) {
        if (check(i)) {
            state.push_back(i);
            cnt[i] = pop_count(i);
        }
    }

    for (int a: state) {
        for (int b: state) {
            if (!(a & b)) head[a].push_back(b);
        }
    }

    for (int i = 1; i <= n+2; i++) {
        for (int a: state) {
            if (a & g[i-1]) continue;
            for (int b: head[a]) {
                if (b & g[i]) continue;
                for (int c: head[b]) {
                    if (b & c) continue;
                    f[i & 1][a][b] = max(f[i & 1][a][b], f[i-1 & 1][c][a] + cnt[b]);
                }
            }
        }
    }

    cout << f[n+2&1][0][0];

    return 0;
}













