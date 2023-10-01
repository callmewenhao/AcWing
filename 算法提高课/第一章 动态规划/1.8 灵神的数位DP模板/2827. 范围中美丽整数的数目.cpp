#include <functional>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int dp(int n, int k) {
        auto s = to_string(n);
        // 数位长度是 m，这一位之前的数模 k 的取值，这一位之前的奇数减去偶数的值（没必要记录奇数和偶数的个数）
        int m = s.length(), memo[m][k][m*2+1]; 
        memset(memo, -1, sizeof memo);
        
        function<int(int, int, int, bool, bool)> f;
        f = [&](int i, int val, int diff, bool is_limit, bool is_num) -> int {
            if (i == m)
                return is_num && val == 0 && diff == m;
            if (!is_limit && is_num && memo[i][val][diff] != -1) 
                return memo[i][val][diff];
            int res = 0;
            if (!is_num) 
                res += f(i + 1, val, diff, false, false);
            int up = is_limit ? s[i] - '0' : 9;
            for (int d = 1 - is_num; d <= up; d++) {
                res += f(i + 1, (val * 10 + d) % k, diff + (d % 2) * 2 - 1, is_limit && d == up, true);
            }
            if (!is_limit && is_num) 
                memo[i][val][diff] = res;
            return res;
        };
        return f(0, 0, m, true, false);
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return dp(high, k) - dp(low - 1, k);
    }
};







