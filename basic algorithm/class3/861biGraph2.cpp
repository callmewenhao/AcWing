/**
 * 二分图
 *
 * 匈牙利算法 求最大匹配
 * 二分图中满足要求的最大匹配数
 *
 * 时间复杂度 O(nm) 但是一般跑不到
 *
 */

#include <cstring>
#include <iostream>

using namespace std;

const int N = 507, M = 1e5 + 7;

int n1, n2, m;
// 使用 邻接表 存 男生指向女生的边
int h[N], e[M], ne[M], idx;
int match[N];  // 存放每个 女生 的匹配结果
bool st[N];  // 为每次找 已分配的男生 的备胎用

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int boy) {
    // 遍历男生能匹配的女生
    for (int i = h[boy]; ~i; i = ne[i]) {
        int girl = e[i];
        if (!st[girl]) { // 女生在一次 find 中还没有被分配      
            st[girl] = true;  // 分配
            // 看看
            if (!match[girl] || find(match[girl])) {
                match[girl] = boy;
                return true;
            }
        }
    }
    return false;
}


int main() {
    // 邻接表
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int boy, girl;
        cin >> boy >> girl;
        add(boy, girl);
    }

    // 找匹配
    int ans = 0;
    for (int boy = 1; boy <= n1; boy++) {
        // 每次重置
        memset(st, false, sizeof st);
        if (find(boy)) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}



