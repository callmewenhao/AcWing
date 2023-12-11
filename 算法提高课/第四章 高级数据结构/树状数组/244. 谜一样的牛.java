import java.util.*;

public class Main {

    static int N = 100_007;
    static int[] a = new int[N];
    static int[] tr = new int[N];
    
    static void add(int idx, int x) {
        for (int i = idx; i < N; i += i & -i) {
            tr[i] += x;
        }
    }

    static int sum(int idx) {
        int s = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            s += tr[i];
        }
        return s;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ans = new int[n+1];

        for (int i = 1; i <= n; i++) {
            tr[i] = i & -i;
        }

        for (int i = 2; i <= n; i++) {
            a[i] = sc.nextInt();
        }

        for (int i = n; i > 0; i--) {
            int x = a[i] + 1;
            int l = 1, r = n;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sum(mid) < x) l = mid + 1;
                else r = mid - 1;
            }
            ans[i] = l;
            add(l, -1);
        }

        for (int i = 1; i <= n; i++) {
            System.out.println(ans[i]);
        }
    }
}
