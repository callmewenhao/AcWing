import java.util.*;

class Solution {
    int m;
    int[] tr = new int[2 * 100_007];

    void add(int idx, int x) {
        for (int i = idx; i <= m; i += i & -i) {
            tr[i] += x;
        }
    }

    int sum(int idx) {
        int s = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            s += tr[i];
        }
        return s;
    }

    public long numberOfPairs(int[] nums1, int[] nums2, int diff) {
        int n = nums1.length;
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int d = nums1[i] - nums2[i];
            set.add(d);
            set.add(d + diff);
        }

        List<Integer> list = new ArrayList<>(set);
        Collections.sort(list);
        Map<Integer, Integer> map = new HashMap<>();
        for (int x: list) map.put(x, ++m);

        long ans = 0;
        for (int i = 0; i < n; i++) {
            int d = nums1[i] - nums2[i];
            ans += sum(map.get(d + diff));
            add(map.get(d), 1);
        }

        return ans;
    }
}
