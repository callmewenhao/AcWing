#include <iostream>

using namespace std;

int n, a; 


int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> a;
        for(int i = 0 ; i < n; i++) {
            cout << char('a' + (i % a)) << " ";
        }
        cout << endl;
    }

    return 0;
}
