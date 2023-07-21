#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    int n;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        cout << endl;
    }

    return 0;
}