#include <iostream>
#include <string>
#include <cstring>
#include <functional>

using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        // 这个题目可以很好的讨论前导零
        vector<int> nums;
        while (n) nums.push_back(n%2), n/=2;
        reverse(nums.begin(), nums.end());

        int m = nums.size(), memo[m][10];
        memset(memo, -1, sizeof memo);

        function<int(int, int, bool)> f;
        f = [&](int i, int last, bool is_limit) -> int {
            if (i == m) return 1;
            if (!is_limit && memo[i][last]!= -1) return memo[i][last];

            int res = 0;
            int up = is_limit ? nums[i] : 1;
            for (int d = 0; d <= up; d++) {
                if (last == 1 && d == 1) continue;
                res += f(i+1, d, is_limit && d == up);
            }
            if (!is_limit) memo[i][last] = res;
            return res;
        };
        return f(0, 0, true);
    }
};







