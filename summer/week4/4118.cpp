#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        int N, M;
        long long D, C;
        cin >> N >> D >> C >> M;

        string S;
        cin >> S;

        int d_n = 0, c_n = 0;
        for (auto ch : S) {
            if (ch == 'D') d_n++;
            if (ch == 'C') c_n++;
        }

        for (char ch : S) {
            if (ch == 'C' && C > 0) {
                C--;
                c_n--;
            } else if (ch == 'D' && D > 0) {
                D--;
                d_n--;
                C += M;
            } else 
                break;
        }
        if (d_n) cout << "Case #" << cases << ": " << "NO" << endl;
        else cout << "Case #" << cases << ": " << "YES" << endl;
    }
    return 0;
}