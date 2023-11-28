class Solution {
    final int N = 50007;
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

    int unique(List<Integer> alls) {
        int i = 0;
        for (int j = 0; j < alls.size(); j++) {
            int x = alls.get(j);
            if (j == 0 || x != alls.get(j-1)) {
                alls.put(i++, x);
            }
        }
    }

    int left_search(List<Integer> alls, int x) {
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
        var alls = Arrays.stream(nums).boxed().collect(Collectors.toList());

        alls = alls.subList(0, unique(alls));

        int ans = 0;
        for (int i = n-1; i >= 0; i--) {
            int x = nums[i];
            int idx = left_search(alls, x) + 1;
            ans += sum(x / 2 - 1);
        }

        return ans;
    }
}


























