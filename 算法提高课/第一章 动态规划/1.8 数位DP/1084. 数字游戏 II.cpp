#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 11, M = 110;

int P;
int f[N][10][M];

int mod(int x, int y) {
    return (x % y + y) % y;
}

void init() {
    memset(f, 0, sizeof f);
    // 边界
    for (int i = 0; i <= 9; i++)
        f[1][i][i % P] = 1;
    // 状态转移
    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < P; k++) {
                for (int x = 0; x <= 9; x++) {
                    f[i][j][k] += f[i - 1][x][mod(k - j, P)];
                }
            }
        }
    }
}

int dp(int n) {
    // 0 符合条件
    if (!n)
        return 1;
    vector<int> nums;
    while (n)
        nums.push_back(n % 10), n /= 10;

    int res = 0;
    int last = 0; // 存前面数的和
    for (int i = nums.size() - 1; i >= 0; i--) {
        int x = nums[i];
        // 不选这一位的数
        for (int j = 0; j < x; j++) {
            res += f[i+1][j][mod(-last, P)];
        }
        // 选这个数 就加上它 然后进行下一个循环
        last += x;
        // 最后的右分支 数都选好了
        if (!i && last % P == 0) res++; 
    }
    return res;
}

int main() {
    int l, r;
    while (cin >> l >> r >> P) {
        init();
        cout << dp(r) - dp(l - 1) << endl;
    }
    return 0;
}
