/**
 * 快排
*/

#include <iostream>

using namespace std;

const int N = 1e5 + 7;
int q[N];

// y 总的快排模板
void quickSort(int *q, int l, int r) {
    // 先判断区间是否合法
    if (r <= l) return;
    // 双指针在区间两侧 pivot 取中间值
    int  i = l - 1, j = r + 1, x = q[(r + l) >> 1];
    while (i < j) {
        // 找到左侧第一个大于等于 x 的位置
        do i++; while (q[i] < x);
        // 找到右侧第一个小于等于 x 的位置
        do j--; while (q[j] > x);
        // 找到的位置合法 就交换数字
        if (i < j) swap(q[i], q[j]);
    }
    // 最终位置 [l, j, i, r]
    // 递归地处理两个子区间 [l, j] [j+1, r] 或者 [l, i-1] [i, r]
    quickSort(q, l, j);  // 但是数据加强了 貌似只有这种写法可以AC
    quickSort(q, j + 1, r);
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    quickSort(q, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", q[i]);
    }

    return 0;
}










