#include <iostream>
#include <string>
#include <cstring>
#include <functional>

using namespace std;

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        auto s = to_string(n);
        int m = s.length(), memo[10][1<<10];
        memset(memo, -1, sizeof memo);

        function<int(int, int, bool, bool)> f;
        f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
            if (i == m) return is_num; // 返回 is_num 就把 0 剔除了
            if (!is_limit && is_num && memo[i][mask] != -1)
                return memo[i][mask];
            
            int res = 0;
            if (!is_num) 
                res = f(i+1, mask, false, false);
            int up = is_limit ? s[i] - '0' : 9;
            for (int d = 1 - is_num; d <= up; d++) {
                if ((mask >> d & 1) == 0)
                    res += f(i+1, mask | (1 << d), is_limit && d == up, true);
            }
            if (!is_limit && is_num)
                memo[i][mask] = res;
            return res;
        };

        return n - f(0, 0, true, false);
    }
};