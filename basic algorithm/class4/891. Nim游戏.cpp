#include <iostream>

using namespace std;

int main() {
    int n, res = 0;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        res ^= x;
    }

    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}




