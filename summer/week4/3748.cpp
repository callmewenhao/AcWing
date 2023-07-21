#include <iostream>

using namespace std;

const int N = 2e5 + 7;
char s[N];

int main() {

    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);

        // output
        printf("Case #%d: ", cases);
        int res = 1;
        printf("%d ", res);
        for (int i = 1; i < n; i++) {
            if (s[i] > s[i-1]) res += 1;
            else res = 1;
            printf("%d ", res);
        }
        puts("");
    }
    return 0;
}