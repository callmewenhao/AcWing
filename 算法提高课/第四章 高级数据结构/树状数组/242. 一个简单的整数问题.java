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
        int n = sc.nextInt(), m = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
            // add(i, a[i] - a[i-1]);
        }

        for (int i = 1; i <= n; i++) {
            int x = a[i] - a[i-1];
            tr[i] += x;
            int nxt = i + (i & -i);
            if (nxt <= n) {
                tr[nxt] += tr[i];
            }
        }

        while (m-- > 0) {
            String op = sc.next();
            if (op.equals("Q")) {
                int idx = sc.nextInt();
                System.out.println(sum(idx));
            } else {
                int l = sc.nextInt(), r = sc.nextInt(), d = sc.nextInt();
                add(l, d);
                add(r+1, -d);
            }
        }
    }
}
