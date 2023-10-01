#include <iostream>
#include <vector>

using namespace std;

const int N = 35;  // 求的是在 B 进制下的方案数 B 最小是 2 对应 31 位

int K, B;
int f[N][N];

// 计算 15 以内的组合数
// y 总的组合数模板
int init = []() -> int {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) f[i][j] = 1;
            else f[i][j] = f[i-1][j-1] + f[i-1][j];
        }
    }
}();

int dp(int n) {
    if (!n) return 0;

    // 得到 n 的 B 进制
    vector<int> nums;
    while (n) nums.push_back(n % B), n /= B;

    // 答案个数
    int res = 0;
    // 前缀信息
    int last = 0;  // 本题表示前面选的这些数中已经有多少个 1 了

    // 从高位到低位枚举
    for (int i = nums.size() - 1; i >= 0; i--) {
        int x = nums[i];
        // 先考虑左侧分支
        if (x > 1) {
            // 选 0
            res += f[i][K - last];
            // 选 1
            if (K - last - 1 >= 0) 
                res += f[i][K-last-1];
            break;
        } else if (x == 1) {
            if (K - last >= 0)
                res += f[i][K - last];
            last++;
            if (last > K) 
                break;
        }
        // 下次循环计算右侧分支的情况
        // 右侧分支的最后一个
        if (!i && last == K) res++; 
    }

    return res;
}

int main() {

    int l, r;
    cin >> l >> r >> K >> B;

    cout << dp(r) - dp(l-1) << endl;

    return 0;
}





