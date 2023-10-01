/**
 * 整数二分
*/

#include <iostream>

using namespace std;

const int N = 1e5 + 7;
int a[N];

int left_search(int l, int r, int k) {
    // 闭区间写法
    int i = l, j = r;
    while (i <= j) {
        int mid = (i + j) >> 1;
        if (a[mid] < k)
            i = mid + 1;  // 向右找
        else
            j = mid - 1;  // 向左找
    }
    return i;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < q; i++) {
        int k;
        scanf("%d", &k);
        int l = left_search(0, n-1, k); // a[l] <= k
        if (l == n || a[l] != k) {
            printf("%d %d\n", -1, -1);
            continue;
        }
        int r = left_search(0, n-1, k + 1) - 1;
        printf("%d %d\n", l, r);
    }
    return 0;
}