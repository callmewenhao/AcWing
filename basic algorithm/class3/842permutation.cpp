/**
 * DFS 
 * 
 * 全排列
*/

#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];  // 路径 or 结果
bool used[N];  // N = 10 可以使用位运算优化

void dfs(int u) {
    // 当遍历到最后一个位置
    if (u == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", path[i]);
        }
        puts("");
    }
    // 枚举能够选哪个数
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            path[u] = i;
            used[i] = true;
            dfs(u+1);
            // 恢复现场
            used[i] = false;
        }
    }
}


int main() {
    cin >> n;
    dfs(0);
    return 0;
}