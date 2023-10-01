#include <iostream>
#include <vector>

using namespace std;

const int N = 13;

// f[i][j] 表示总共 i 位，且最高位是 j 的 Windy 数的个数
// f[i][j] 是包含前导零的情况的，而含前导零的情况会漏数
// 比如：0157 这个数其实是 157，是一个 Windy 数，但是由于前导零的存在 这个数没有算进 f[4][0] 中
// 对于这些含前导 0 的数，需要找到真的最高位，比如 0157 中的 1，然后特判计算 f[3][1]（包含 157），这样就可以把这个数算进去了
// 主要原因还是有些 0 没有意义，不能作为是否是 Windy 数的条件
int f[N][10];

void init() {
    // f[i][j] += f[i-1][k]  k j 之间至少差 2
    // f[1][j] = 1
    for (int i = 0; i <= 9; i++) f[1][i] = 1;
    for (int i = 2; i < N; i ++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (abs(j - k) >= 2) {
                    f[i][j] += f[i-1][k];
                }
            }
        }
    } 
}

int dp(int n) {
    // 0 不在区间内 但是题目要求不含前导零 0 就是不合法的数字 故返回 0
    if (!n) return 0; 
    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;

    int res = 0;
    int last = -2;  // 还是上一个数，-2 保证最高位可以任意填


    // 不含前导零的数
    for (int i = nums.size() - 1; i >= 0; i--) {
        int x = nums[i];
        // 左侧分支
        // 注意 i = n-1 时只能从 1 开始
        // i < n-1 时可以从 0 开始
        for (int j = (i == nums.size() - 1); j < x; j++) {
                if (abs(j - last) >= 2) {
                    res += f[i+1][j];
                }
        }
        // 判断能否继续进行右侧分支
        if (abs(x - last) < 2) break;
        last = x;
        if (!i) res++;
    }
    
    // 含前导零的数
    // 0xx...x 一共 1~n-1位，最高位不取 0
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 1; j <= 9; j++) {
            res += f[i][j];
        }
    }

    return res;
}


int main() {

    init();

    int l, r;
    cin >> l >> r;
    cout << dp(r) - dp(l-1) << endl;

    return 0;
}



