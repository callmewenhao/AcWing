#include <iostream>

using namespace std;

int n;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}


int main() {
    cin >> n;

    int a, b;
    while (n--) {
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    
    return 0;
}