#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;

    char kick[4] = {'K', 'I', 'C', 'K'};
    char start[5] = {'S', 'T', 'A', 'R', 'T'};
    for (int cases = 1; cases <= T; cases++) {
        string s;
        cin >> s;

        int k = 0, ans = 0; 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'K') {
                int j = 0;
                for (; j < 4; j++) {
                    if (s[i + j] != kick[j]) {
                        break;
                    }
                }
                if (j == 4) {
                    k++;  // 可以重叠🧐
                }
            } else if (s[i] == 'S') {
                int j = 0;
                for (; j < 5; j++) {
                    if (s[i + j] != start[j]) {
                        break;
                    }
                }
                if (j == 5) {
                    ans += k;
                    i = i + j - 1;
                }
            }
        }
        cout << "Case #" << cases << ": " << ans << endl;
    }

    return 0;
}