#include <cstring>
#include <functional>
#include <vector>

using namespace std;

class Solution {
   public:
    int countSpecialNumbers(int n) {
        auto s = to_string(n);

        int m = s.length(), memo[m][1 << 10];  // 只需记忆化 i mask
        memset(memo, -1, sizeof memo);

        // 数位 dp 记搜模板
        // i：当前要填的数位 mask：已经使用的数的集合
        // is_limit：这一位的选择是否有数字上限限制
        // is_num：这一位之前是否已经选过数
        function<int(int, int, bool, bool)> f;
        f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
            // 当遍历到最后一位（最低位）时
            // 如果前面选过数，那就表示选的这些数是一个合法方案
            // 没选过则表示前面啥也没选，不是一个合法方案
            if (i == m)
                return is_num;

            // 如果没有限制的话，会出现重复情况，因此需要记忆化
            // 而且前面必须选过数字，因为没选过数字的情况只会遇到一次
            if (!is_limit && is_num && memo[i][mask] != -1)
                return memo[i][mask];

            // 首次计算答案
            int res = 0;
            // 这一位可以继续不选数
            if (!is_num)  // 继续枚举 i+1 位 mask 不变 没有限制 没有选数字
                res = f(i + 1, mask, false, false);
            // 选数字
            // 先计算选数字的上限，如果有限制，就只能选到 s[i]
            int up = is_limit ? s[i] - '0' : 9;
            // 在计算选数字的下限，如果之前没选数字，就要从 1 开始
            int low = 1 - is_num;
            // 枚举选择，累计答案
            for (int d = low; d <= up; d++) {
                // 如果 d 不在 mask 中
                if ((mask >> d & 1) == 0)
                    // 继续枚举 i+1 位 mask 中加入 d
                    // 如果之前有些限制并且选到了 up 那就继续有限制
                    // 这一位已经选数字了
                    res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
            }
            // 保存需要记忆化的答案
            if (!is_limit && is_num)
                memo[i][mask] = res;
            return res;
        };
        // 入口从第 0 位开始，mask 集合啥也没有
        // 第一位有限制 最大选s[0]，前面没选过数字
        return f(0, 0, true, false);
    }
};