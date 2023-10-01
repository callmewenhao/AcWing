/**
 * spfa
 * 
 * 判断是否具有负环
 * 
 * dist 数组表示 当前最短路距离
 * cnt 数组表示 边数
 * 
 * 更新公式
 * dist[x] = dist[t] + w[i]
 * cnt[x] = cnt[t] + 1
 * 
 * if cnt[x] >= n 意味着存在负环
 * 
 * 注意：
 * dist数组赋值为0不等于没赋值，赋值为0意思是开始虚拟一个源点，
 * 这个源点到其他点的距离为0，然后效果等价于初始时把各个点加到队列中
 * 
 * 不管dist数组的初值是多少，都是可以的。
 * 因为只要有负环存在，就必然有某些点的距离是负无穷，
 * 所以不管距离被初始化成何值，都一定严格大于负无穷，所以一定会被无限更新。
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e4+7;

int n, m;
int h[N], e[N], w[N], ne[N], idx;
int dist[N], cnt[N];
bool st[N]; 

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }
    

    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;

        // 遍历 t 的边
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n) {
                    return true;
                }
                if (!st[j]) {  // 能不能放入 j
                    q.push(j);
                    st[j] = true; 
                }
            }
        }
    }
    return false;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);

    // 初始化
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    // spfa 算法
    if (spfa()) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}






