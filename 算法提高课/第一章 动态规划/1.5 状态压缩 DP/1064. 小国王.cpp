#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int N = 12, M = 1 << 10, K = 110;

int n, k;
vector<int> state;
int cnt[M];
vector<int> head[M];
ll f[N][K][M];

bool check(int x) {
    for (int i = 0; i < n; i++)
        if ((x >> i & 1) && (x >> (i+1) & 1))
            return false;
    return true;
}

int pop_count(int x) {
    int res = 0;
    for (int i = 0; i < n; i++)
        if (x >> i & 1) res++;
    return res;
}

int main () {

    cin >> n >> k;
    
    // 统计合法状态 顺便统计状态中 1 的个数
    for (int i = 0; i < 1 << n; i++) {
        if (check(i)) {
            state.push_back(i);
            cnt[i] = pop_count(i);
        }
    }

    // 统计合法状态之间的转移
    for (int a: state) {
        for (int b: state) {
            if ((a&b) == 0 && check(a|b)) {
                head[a].push_back(b);
            }
        }
    }

    // 状态转移
    f[0][0][0] = 1;
    for (int i = 1; i <= n+1; i++) {
        for (int j = 0; j <= k; j++) {
            for (int a: state) {
                for (int b: head[a]) {
                    int c = pop_count(b);
                    if (j >= c) 
                        f[i][j][a] += f[i-1][j-c][b];
                }
            }
        }
    }

    cout << f[n+1][k][0];

    return 0;
}




