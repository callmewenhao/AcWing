#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>

using namespace std;


class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> nums;
        for (auto str: digits) {
            nums.push_back(stoi(str));
        }

        auto s = to_string(n);
        int m = s.length(), memo[m];
        memset(memo, -1, sizeof memo);
        
        function<int(int, bool, bool)> f = [&](int i, bool is_limit, bool is_num) -> int {
            if (i == m) return is_num;
            if (!is_limit && is_num && memo[i] != -1) return memo[i];

            int res = 0;
            if (!is_num) 
                res = f(i+1, false, false);
            
            // 要确定能选哪些数
            int x = is_limit ? s[i] - '0': 9;
            int l = 0, r = nums.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums[mid] < x + 1)  
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
            // cout << x << " " << r << " " << nums[r] << endl;
            for (int d = 0; d <= r; d++) {
                res += f(i+1, is_limit && nums[d] == (s[i] - '0'), true);
            }
            if (!is_limit && is_num) 
                memo[i] = res;
            return res;
        };

        return f(0, true, false);
    }
};

