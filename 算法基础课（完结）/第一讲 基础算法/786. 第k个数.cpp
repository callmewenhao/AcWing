/**
 * 第 K 个数
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;
int q[N];

int quick_sort(int q[], int l, int r, int k) {
    if (l == r) return q[l];
    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    while (i < j) {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    if (k <= (j - l + 1))  // 不是 k <= j! 要有递归的思想
        return quick_sort(q, l, j, k);
    return quick_sort(q, j + 1, r, k - (j - l + 1));
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
//    nth_element(q, q + k - 1, q + n);
//    printf("%d", q[k - 1]);
    printf("%d", quick_sort(q, 0, n-1, k));
    return 0;
}




