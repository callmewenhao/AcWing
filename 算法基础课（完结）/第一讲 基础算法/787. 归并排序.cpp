/**
 * 归并排序
*/
#include <iostream>

using namespace std;

const int N = 1e5+10;

int n, a[N], temp[N];

void merge_sort(int a[], int l, int r) {
    // 判断区间是否合法
    if (r <= l) return;
    // 划分两个子区间 
    int mid = (l + r) >> 1;
    // 递归处理两个子区间
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    // 合并两个有序的子区间
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    // 移动元素
    for (i = l, j = 0; i <= r; i++, j++) {
        a[i] = temp[j];
    }
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    merge_sort(a, 0, n-1);

    for (int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}





