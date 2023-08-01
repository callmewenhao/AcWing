#include <iostream>

using namespace std;
using LL = long long;

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
        int a, b, m, x, y;
        cin >> a >> b >> m;
        int d = exgcd(a, m, x, y);
        if (b % d) cout << "impossible" << endl;
        else cout << (LL) x * (b / d) % m << endl;  // 最后还需要 mod m
    }

    return 0;
}



