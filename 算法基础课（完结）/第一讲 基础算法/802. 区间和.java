public class Main {
    class Pair {
        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
        
        int a;
        int b;
    }

    static int N = 300_007;
    int[] a = new int[N], s = new int[N];

    List<Integer> alls = new ArrayList<>();
    List<Pair> add = new ArrayList<>(), query = new ArrayList<>();

    private int left_search(List<Integer> alls, int x) {
        int left = 0, right = alls.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (alls.get(mid) < x) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }

    private int unique(List<Integer> alls) {
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

        


    }
}