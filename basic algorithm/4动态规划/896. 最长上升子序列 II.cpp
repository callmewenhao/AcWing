/**
 * 难度在于数据范围变大了
 * 
 * 维护每一种长度的上升子序列的 最小结尾数字，
 * 那么答案就是所维护到的的最大长度
 * 显然，随着 长度的增加 结尾的数字在严格单调递增
 * 
 * 当 处理到元素 ai 时，可以 二分 找到比 ai 小的最大的数 bi 
 * 则 ai 对应的长度 = bi 对应的长度 + 1，然后更新长度对应的元素为 ai
 * 
 * 整体思路更像贪心
 * 
*/
#include <iostream>

using namespace std;

const int N = 1e5+7;

int n, a[N], q[N];

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int len = 0;
    q[0] = -2e9; // 最小值 保证二分的值都比 q[0] 大
    for (int i = 1; i <= n; i++) {
        // 二分闭区间模板
        int l = 0, r = len;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (q[mid] >= a[i]) r = mid - 1;
            else l = mid + 1;
        }
        // r 就是我们要找的下标
        len = max(r + 1, len);  // 其实 r + 1 就是 l
        q[r + 1] = a[i];
    }

    cout << len << endl;

}




