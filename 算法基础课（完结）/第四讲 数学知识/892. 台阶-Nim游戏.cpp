#include <iostream>

using namespace std;

int main() {
    int n, res = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i % 2) res ^= x;
    }

    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}




