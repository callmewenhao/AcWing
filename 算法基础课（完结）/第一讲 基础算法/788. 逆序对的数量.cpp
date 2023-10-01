/**
 * 逆序对
*/

#include <iostream>

using namespace std;

using LL = long long; // 注意数据范围

const int N = 1e5 + 7;
int q[N], temp[N];

// 使用 merge_sort 计算逆序对
LL merge_sort(int *q, int l, int r) {
    if (l >= r) return 0;
    int mid = (r - l) / 2 + l;

    // 先递归
    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    // 后合并
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) temp[k++] = q[i++];
        else {
            // 计算当前合并碰到的逆序对
            res += (mid - i + 1);
            temp[k++] = q[j++];
        }
    }
    while (i <= mid) temp[k++] = q[i++];
    while (j <= r) temp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = temp[j];
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    LL ans = merge_sort(q, 0, n - 1);
    printf("%ld", ans);
    return 0;
}