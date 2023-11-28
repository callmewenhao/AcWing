import java.util.*;

class Solution {
    int m;
    int[] tree = new int[100_007 * 3];

    void add(int idx, int x) {
        for (int i = idx; i <= m; i += i & -i) {
            tree[i] += x;
        }
    }

    int sum(int idx) {
        int s = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            s += tree[i];
        }
        return s;
    }

    public int countRangeSum(int[] nums, int lower, int upper) {
        Set<Long> set = new HashSet<>();
        
        long s = 0;
        set.add(s);
        for (int x: nums) {
            s += x;
            set.add(s);
            set.add(s - lower);
            set.add(s - upper);
        }

        List<Long> list = new ArrayList<>(set);
        Collections.sort(list);
        Map<Long, Integer> map = new HashMap<>();
        for (long x: list) {
            map.put(x, ++m);
        }

        s = 0;
        int ans = 0;
        add(map.get(s), 1);
        for (int x: nums) {
            s += x;
            int left = map.get(s - upper) - 1;
            int right = map.get(s - lower);
            ans += sum(right) - sum(left);
            add(map.get(s), 1);
        }
        return ans;
    }
}