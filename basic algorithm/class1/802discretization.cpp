/**
 * 整数离散化
 * 找到要离散化的所有元素
 * 排序
 * 去重
 * 二分 找到映射位置
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 3e5 + 7;
int a[N], s[N];  // 映射后的数组, 前缀和数组

// 待映射的元素
vector<int> alls;
vector<pair<int, int>> add, query;

int left_search(vector<int>& alls, int x) {
    int l = 0, r = alls.size() - 1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (alls[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

vector<int>::iterator unique(vector<int>& alls) {
    int i = 0;  
    for (int j = 0; j < alls.size(); j++) {
        if (!j || alls[j] != alls[j-1]) {
            alls[i++] = alls[j];
        }
    }
    return alls.begin() + i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.emplace_back(x, c);
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.emplace_back(l, r);
        alls.push_back(l);
        alls.push_back(r);
    }

    // sort + 去重
    sort(alls.begin(), alls.end());
    // 使用 C++ algorithm 中自带的 unique
    // alls.erase(unique(alls.begin(), alls.end()), alls.end());
    alls.erase(unique(alls), alls.end());  // 手动去重函数

    // 修改
    for (auto [x, c] : add) {
        // 离散化 寻找映射位置
        int idx = left_search(alls, x) + 1;  // 下标从 1 开始
        a[idx] += c;
    }

    // 前缀和
    for (int i = 1; i <= alls.size(); i++) {
        s[i] = s[i - 1] + a[i];
    }

    // 查询
    for (auto [l, r] : query) {
        // 离散化
        l = left_search(alls, l) + 1;
        r = left_search(alls, r) + 1;
        cout << s[r] - s[l-1] << endl;
    }

    return 0;
}