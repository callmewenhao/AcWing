/*
要发现一个重要性质：

最终走的路径无非是：

- 车
- 人
- 车 + 人
- 不会出现 人 + 车

*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

const int N = 2e5+7;

int n, w, d;
int dist[N], a[N];

int h[N], e[N], ne[N], idx;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void bfs() {
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (int i = h[x]; ~i; i = ne[i]) {
            int y = e[i];
            if (dist[y] > 1 + dist[x]) {
                dist[y] = 1 + dist[x];
                q.push(y);
            }
        }
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> w >> d;
    
    memset(h, -1, sizeof h);
    for (int i = 0; i < w; i++) {
        int a, b;
        cin >> a >> b;
        add(b, a);
    }
    
    memset(dist, 0x3f, sizeof dist);
    bfs();
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    multiset<int> S;
    for (int i = 1; i <= n; i++) {
        S.insert(i - 1 + dist[a[i]]);
    }
    
    while (d--) {
        int x, y;
        cin >> x >> y;
        
        S.erase(S.find(x - 1 + dist[a[x]]));
        S.erase(S.find(y - 1 + dist[a[y]]));
        
        swap(a[x], a[y]);
        
        S.insert(x - 1 + dist[a[x]]);
        S.insert(y - 1 + dist[a[y]]);
        
        cout << *S.begin() << endl;
    }
    
    return 0;
}