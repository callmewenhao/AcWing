import java.util.*;

class Solution {
    final int N = 100_007;
    int[] tree = new int[N];

    private void add(int idx, int x) {
        for (int i = idx; i < N; i += i & -i) {
            tree[i] += x;
        }
    }

    private int sum(int idx) {
        int s = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            s += tree[i];
        }
        return s;
    }

    private int unique(int[] alls) {
        int i = 0;
        for (int j = 0; j < alls.length; j++) {
            if (j == 0 || alls[j] != alls[j-1]) {
                alls[i++] = alls[j];
            }
        }
        return i;
    }

    private int left_search(int[] alls, int x) {
        int left = 0, right = alls.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (alls[mid] < x) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }

    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        var alls = Arrays.copyOf(nums, n);
        
        Arrays.sort(alls);
        alls = Arrays.copyOfRange(alls, 0, unique(alls));

        List<Integer> ans = new ArrayList<>();
        for (int i = n-1; i >= 0; i--) {
            int x = nums[i];
            int idx = left_search(alls, x) + 1;
            ans.add(sum(idx-1));
            add(idx, 1);
        }
        Collections.reverse(ans);
        return ans;
    }
}