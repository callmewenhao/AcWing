/**
 * 试除法 分解质因数
*/


#include <iostream>

using namespace std;

int n;

void divide(int a) {
    for (int i = 2; i <= a / i; i++) {
        if (a % i == 0) {
            int s = 0;
            while (a % i == 0) {
                a /= i;
                s++;
            }
            cout << i << " " << s << endl;
        }
    }
    if (a > 1) cout << a << " " << 1 << endl;
    cout << endl;
}

int main() {
    cin >> n;

    int a;
    while (n--) {
        cin >> a;
        divide(a);
    }
    return 0;
}




