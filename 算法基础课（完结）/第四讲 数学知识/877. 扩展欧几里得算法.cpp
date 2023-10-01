#include <iostream>

using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int n;
    cin >> n;

    while (n--) {
        int a, b, x, y;
        cin >> a >> b;
        exgcd(a, b, x, y);

        cout << x << " " << y << endl;
    }

    return 0;
}






