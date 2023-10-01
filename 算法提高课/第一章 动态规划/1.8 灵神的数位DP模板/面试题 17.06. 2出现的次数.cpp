#include <iostream>
#include <string>
#include <cstring>
#include <functional>

using namespace std;


class Solution {
public:
    int numberOf2sInRange(int n) {
        auto s = to_string(n);
        int m = s.length(), memo[10][10];
        memset(memo, -1, sizeof memo);

        function<int(int, int, bool)> f;
        f = [&](int i, int last, bool is_limit) -> int {
            if (i == m) return last;
            if (!is_limit && memo[i][last] != -1) return memo[i][last];

            int res = 0;
            int up = is_limit ? s[i] - '0' : 9;
            for (int d = 0; d <= up; d++) {
                res += f(i+1, last + (d == 2), is_limit && d == up);
            }
            if (!is_limit) memo[i][last] = res;
            return res;
        };

        return f(0, 0, true);

    }
};