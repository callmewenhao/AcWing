/**
 * 八数码
 * 
 * 基本思路
 * 把棋盘状态看作是图中的一个点 则有 起点状态 和 终点状态
 * 相连的点之间权重为 1
 * 目标就是找到 起点状态 和 终点状态 的最短的路径
 * 
 * 难点在于
 * 如何记录状态 --> 使用字符串记录状态
 * 以及状态距离 --> 使用 stl 的 unordered_map 存储 
 * 另外 第一次遇到的距离肯定是最小距离
 * 
 * 状态转移
 * 枚举状态中 x 的上下左右合法位置然后交换
 * 
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(string start) {
    string end = "12345678x";  // 开始状态
    queue<string> q;  // 队列
    unordered_map<string, int> d;  // 存储节点距离

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    q.push(start);
    d[start] = 0;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int dis = d[t];
        if (t == end) return dis;

        // 状态转移
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && 0 <= ny && nx < 3 && ny < 3) {
                // 交换
                swap(t[k], t[nx * 3 + ny]);
                // 如果新状态没遇到过
                if (!d.count(t)) {
                    d[t] = dis + 1;
                    q.push(t);
                }
                // 换回去
                swap(t[k], t[nx * 3 + ny]);
            }
        }
    }
    return -1;
}

int main() {

    string start;
    for (int i = 0; i < 9; i++) {
        char ch;
        cin >> ch;
        start += ch;
    }

    cout << bfs(start);

    return 0;
}










