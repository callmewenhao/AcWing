#include <iostream>

using namespace std;

const int N = 13;

int n;

int main() {

    cin >> n;
    int mn = 32, a3 = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        mn = min(mn, a);
        if (i == 3) a3 = a; 
    }

    cout << (mn ^ a3) + 2 << endl;

    return 0;
}





