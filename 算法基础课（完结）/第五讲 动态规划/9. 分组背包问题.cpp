/**
分组背包
组内物品时互斥的，要么不选组内物品，要么只选其中一个
// 枚举物品组
for (int i = 0 ; i< n; i++) {
    // 枚举体积
    for (int j = m; j >= v; j--) {
        // 再去枚举组内选哪个或者一个也不选
        // v 和 w 只要存储组内的数据就可以了
        f[j] = max(f[j], f[j-w[0]] + w[0], f[j-w[1]] + w[1], ..., f[j-w[s-1]] + w[s-1])
    }
}
总的时间复杂度就是 n^3
*/
#include <iostream>

using namespace std;

const int N = 107;

int n, m;
int v[N], w[N], f[N];

int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) cin >> v[j] >> w[j];
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k < s; k++) {
                if (j >= v[k]) f[j] = max(f[j], f[j-v[k]] + w[k]);
            }
        }
    }

    cout << f[m] << endl;

    return 0;

}

