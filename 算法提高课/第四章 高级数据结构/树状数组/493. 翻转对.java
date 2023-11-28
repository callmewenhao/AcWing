import java.util.*;

class Solution {
    final int N = 100007;
    int[] tree = new int[N];

    void add(int idx, int x) {
        for (int i = idx; i < N; i += i & -i) {
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

    int unique(List<Long> alls) {
        int i = 0;
        for (int j = 0; j < alls.size(); j++) {
            long x = alls.get(j);
            if (j == 0 || x != alls.get(j-1)) {
                alls.set(i++, x);
            }
        }
        return i;
    }

    int left_search(List<Long> alls, long x) {
        int left = 0, right = alls.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (alls.get(mid) < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    public int reversePairs(int[] nums) {
        int n = nums.length;
        List<Long> alls = new ArrayList<>();

        for (long x: nums) {
            alls.add(x);
            alls.add(2 * x);
        }

        Collections.sort(alls);
        alls = alls.subList(0, unique(alls));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            long x = nums[i];
            int idx = left_search(alls, 2 * x) + 1;
            ans += sum(2 * n) - sum(idx);
            idx = left_search(alls, x) + 1;
            add(idx, 1);
        }

        return ans;
    }
}


