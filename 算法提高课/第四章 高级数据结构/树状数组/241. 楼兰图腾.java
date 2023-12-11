import java.util.*;

public class Main {
    static int N = 200_007;
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
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }

        int[] up = new int[N];
        int[] down = new int[N];

        for (int i = 1; i <= n; i++) {
            int x = a[i];
            up[i] = sum(n) - sum(x);
            down[i] = sum(x-1);
            add(x, 1);
        }
        
        Arrays.fill(tr, 0);
        long r1 = 0, r2 = 0;
        for (int i = n; i > 0; i--) {
            int x = a[i];
            r1 += 1l * up[i] * (sum(n) - sum(x));
            r2 += 1l * down[i] * sum(x-1);
            add(x, 1);
        }

        System.out.println(r1 + " " + r2);
    }
}
