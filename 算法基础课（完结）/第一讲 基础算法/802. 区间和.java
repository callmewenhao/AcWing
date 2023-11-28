import java.util.*;
import java.util.Collections;

public class Main {
    static class Pair {
        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
        
        int a;
        int b;
    }

    static int N = 300_007;
    static int[] a = new int[N], s = new int[N];

    static List<Integer> alls = new ArrayList<>();
    static List<Pair> add = new ArrayList<>(), query = new ArrayList<>();

    private static int left_search(List<Integer> alls, int x) {
        int left = 0, right = alls.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (alls.get(mid) < x) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }

    private static int unique(List<Integer> alls) {
        int i = 0;
        for (int j = 0; j < alls.size(); j++) {
            int x = alls.get(j);
            if (j == 0 || x != alls.get(j-1)) {
                alls.set(i++, x);
            }
        }
        return i;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();

        for (int i = 0; i < n; i++) {
            int x = sc.nextInt(), c = sc.nextInt();
            add.add(new Pair(x, c));
            alls.add(x);
        }

        for (int i = 0; i < m; i++) {
            int l = sc.nextInt(), r = sc.nextInt();
            query.add(new Pair(l, r));
            alls.add(l);
            alls.add(r);
        }
        
        // 排序 + 去重
        Collections.sort(alls);
        alls = alls.subList(0, unique(alls));
        
        // 修改
        for (var p: add) {
            int idx = left_search(alls, p.a) + 1;
            a[idx] += p.b;
        }

        // 前缀和
        for (int i = 1; i <= alls.size(); i++) {
            s[i] = s[i-1] + a[i];
        }

        // 查询
        for (var p: query) {
            int l = p.a, r = p.b;
            l = left_search(alls, l) + 1;
            r = left_search(alls, r) + 1;
            System.out.println(s[r] - s[l-1]);
        }
    }
}