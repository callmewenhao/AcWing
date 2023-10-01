#include <cstring>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    // 这题甚至可以不用 is_num 因为前导零不影响 1 的个数
    int countDigitOne(int n) {
        auto s = to_string(n);
        int m = s.length(), memo[11][11];  // memo[m][m] 也行
        memset(memo, -1, sizeof memo);

        function<int(int, int, bool, bool)> f;
        f = [&](int i, int last, bool is_limit, bool is_num) -> int {
            if (i == m && is_num)
                return last;
            if (!is_limit && is_num && memo[i][last] != -1)
                return memo[i][last];
            int res = 0;
            if (!is_num)
                res += f(i + 1, last, false, false);
            int up = is_limit ? s[i] - '0' : 9;
            for (int d = 1 - is_num; d <= up; d++) {
                res += f(i + 1, last + (d == 1), is_limit && d == up, true);
            }
            if (!is_limit && is_num)
                memo[i][last] = res;
            return res;
        };
        return f(0, m, true, false);
    }

    // 不用 is_num
    /*
    int countDigitOne(int n) {
        auto s = to_string(n);
        int m = s.length(), memo[11][11];
        memset(memo, -1, sizeof memo);

        function<int(int, int, bool)> f;
        f = [&](int i, int last, bool is_limit) -> int {
            if (i == m)
                return last;
            if (!is_limit && memo[i][last] != -1)
                return memo[i][last];
            int res = 0;
            int up = is_limit ? s[i] - '0' : 9;
            for (int d = 0; d <= up; d++) {
                res += f(i + 1, last + (d == 1), is_limit && d == up);
            }
            if (!is_limit)
                memo[i][last] = res;
            return res;
        };
        return f(0, 0, true);
    }
    */
};
