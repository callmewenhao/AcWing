#include <iostream>
#include <vector>

using namespace std;

const int N = 15;

// f[i][j] 表示一共 i 位，且最高位为 j 的不降数的个数
int f[N][10];

void init() {
    for (int i = 0; i <= 9; i++) f[1][i] = 1;
    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = j; k <= 9; k++) {
                f[i][j] += f[i-1][k];
            }
        }
    }
}

int dp(int n) {
    // 0 要特判
    if (!n) return 1;
    // 其他数拆到 nums 中
    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;

    int res = 0; // 方案数
    // 前缀信息：选定的这些数是否是不降的，只需要存上一个数就行
    int last = 0; // 确保每次从 last 开始取数 

    for (int i = nums.size() - 1; i >= 0; i--) {
        // 左侧分支
        int x = nums[i];
        for (int j = last; j < x; j++) {
            res += f[i+1][j];
        }
        // 当前这位能不能填 x 不能就结束
        if (last > x) break;
        last = x;
        // 当安全的到达 最后的右侧分支
        if (!i) res++; 
    }
    return res;
}

int main() {

    init();

    int l, r;
    // 当读到文件结束符时 结束循环
    while (cin >> l >> r) {
        cout << dp(r) - dp(l-1) << endl;
    }

    return 0;
}





