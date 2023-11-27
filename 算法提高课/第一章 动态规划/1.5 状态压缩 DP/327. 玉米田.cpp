#include <iostream>
#include <vector>

using namespace std;

const int N = 14, M = 1 << N, MOD = 1e8;

int n, m, g[N];
vector<int> state;
vector<int> head[M];
int f[N][M];

bool check(int x) {
    for (int i = 0; i < m+1; i++)  // 理论上要加一 但是前面是 0 不加一不会误判
        if (x >> i & 1 && x >> (i+1) & 1) 
            return false;
    return true;
}

int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            g[i] |= x * (1 << j);
        }
    }

    for (int i = 0; i < 1 << m; i++)
        if (check(i))
            state.push_back(i);
    
    for (int a: state) {
        for (int b: state) {
            if (!(a & b)) 
                head[a].push_back(b);
        }
    }

    f[0][0] = 1;
    for (int i = 1; i <= n+1; i++) {
        for (int a: state) {
            // 注意 != 和 == 的优先级比位运算高，记得加括号 
            if ((a & g[i]) != a) continue; // 这里 a 必须是 g[i] 的子集
            for (int b: head[a]) {
                f[i][a] = (f[i][a] + f[i-1][b]) % MOD;
            }
        }
    }

    cout << f[n+1][0];

    return 0;
}



