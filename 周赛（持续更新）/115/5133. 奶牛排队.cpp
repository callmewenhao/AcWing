/*
参考题解：
https://www.acwing.com/solution/content/198886/

性质：
1. 起点和终点在 a b 中的出现次数只可能为 1
2. 起点出现在 a 中，而终点出现在  b 中
3. 用 hashmap 维护一个前后指向关系 ai->bi，根据起点和起点后面的一个元素，就可以推出整只队伍
*/

#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 2e5+7;

int n, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    // 记录数据
    cin >> n;
    
    unordered_map<int, int> map;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        map[a[i]]++;
        map[b[i]]++;
    }
    
    // 找到起点和终点
    int start, end;
    for (int i = 1; i <= n; i++) {
        if (map[a[i]] == 1) start = a[i];
        if (map[b[i]] == 1) end = b[i];
    }
    // cout << start << " " << end << endl;

    // 记录前后指向关系
    map.clear();
    for (int i = 1; i <= n; i++) {
        map[a[i]] = b[i];
    }

    // 找整个队列
    cout << start << " ";
    int last = start, nxt = map[0];
    while (map.count(nxt)) {
        cout << nxt << " ";
        int t = nxt;
        nxt = map[last];
        last = t;
    }
    cout << end << endl;

    return 0;
}
