import java.util.*;

public class Main {
    static int N = 100_007;
    static int[] a = new int[N];
    static long[] tr1 = new long[N];
    static long[] tr2 = new long[N];

    static void add(long[] tr, int idx, int x) {
        for (int i = idx; i < N; i += i & -i) {
            tr[i] += x;
        }
    }

    static long sum(long[] tr, int idx) {
        long s = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            s += tr[i];
        }
        return s;
    }

    static long preSum(int idx) {
        return sum(tr1, idx) * (1 + idx) - sum(tr2, idx);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
            // add(i, a[i] - a[i-1]);
        }

        for (int i = 1; i <= n; i++) {
            int x = a[i] - a[i-1];
            tr1[i] += x;
            tr2[i] += 1l*i*x;
            int nxt = i + (i & -i);
            if (nxt <= n) {
                tr1[nxt] += tr1[i];
                tr2[nxt] += tr2[i];
            }
        }

        while (m-- > 0) {
            String op = sc.next();
            if (op.equals("Q")) {
                int l = sc.nextInt(), r = sc.nextInt();
                System.out.println(preSum(r) - preSum(l-1));
            } else {
                int l = sc.nextInt(), r = sc.nextInt(), d = sc.nextInt();
                add(tr1, l, d); add(tr2, l, l*d);
                add(tr1, r+1, -d); add(tr2, r+1, -(r+1)*d);
            }
        }
    }
}
