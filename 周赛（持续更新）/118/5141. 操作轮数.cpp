#include <iostream>

using namespace std;

using LL = long long;

LL a, b;

int main() {

    cin >> a >> b;

    int res = 0;
    while (a && b) {
        res += a / b;
        a = a % b;
        swap(a, b);
    }

    cout << res << endl;

    return 0;
}


