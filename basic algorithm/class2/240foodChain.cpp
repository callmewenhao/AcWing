/**
 * 使用并查集维护额外信息
 * 
 * 我们把遍历到的合法的点都放进一棵树中
 * 同时 使用点到根节点的距离代表种类
 * 距离 % 3 == 0 表示和根节点一类
 * 距离 % 3 == 1 表示吃根节点的一类
 * 距离 % 3 == 2 表示吃 距离 % 3 == 1 的一类 同时被 根节点一类吃
 * 
*/
#include <iostream>

using namespace std;

const int N = 1e5+7;

int p[N], d[N];

// 找到根节点 同时维护节点到父节点的距离
int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    // 判断真假
    int res = 0;
    while (m--) {
        int t, x, y;
        cin >> t >> x >> y;

        if (x > n || y> n) res++;
        else {
            int px = find(x), py = find(y);
            if (t == 1) {
                // 判断是不是同一类
                if (px == py && (d[x] - d[y]) % 3) res++;
                else if (px != py) {  // 作为真话合并成一棵树
                    p[px] = py;  // py 作为新根
                    d[px] = d[y] - d[x];  // 更新 d[px]
                }
            } else {
                // 判断吃与被吃关系
                if (px == py && (d[x] - d[y] - 1) % 3) res++;
                else if (px != py) { // 作为真话合并成一棵树
                    p[px] = py;  // py 作为新根
                    d[px] = d[y] - d[x] + 1;  // 更新 d[px]
                }
            }
        }
    }

    cout << res <<endl;

    return 0;
}

