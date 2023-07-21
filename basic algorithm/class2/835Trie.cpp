/**
 * Trie 树
 *
 * 高效地存储和查找字符串集合的数据结构
 *
 * son[N][26] 存每个节点的所有儿子
 *
 * cnt[N] 以当前这个点结尾的单词有多少个
 *
 * idx 当前已经分配的下标
 * 注意 idx = 0 是根节点 而且是空节点
 */
#include <iostream>

using namespace std;

// trie 树
const int N = 1e5 + 7;
int son[N][26], cnt[N], idx;

// 插入新字符串
void insert(char* str) {
    int p = 0;  // 起始父节点
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx; // 如果儿子不存在就新建
        p = son[p][u];  // 更新父节点
    }
    cnt[p]++; // 以这个点结尾的字符串又多了一个
}

// 查询字符串个数
int query(char * str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char op[2], str[N];
        cin >> op >> str;

        if (op[0] == 'I') insert(str);
        else if (op[0] == 'Q') {
            cout << query(str) << endl;
        }
    }
    
    return 0;
}