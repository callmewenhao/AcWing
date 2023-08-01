#include <iostream>
#include <unordered_map>

using namespace std;
using LL = long long;

const int MOD = 1e9+7;

int n;
unordered_map<int, int> primes;

int main() {
    cin >> n;
    int x;
    while (n--) {
        cin >> x;
        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {
                x /= i;
                primes[i]++;
            }
        }
        if (x > 1) primes[x]++;
    }

    // 计算个数
    LL ans = 1;
    for (auto [b, p]: primes) {
        LL t = 1; 
        while (p--) t = (t * b + 1) % MOD;  // 这里也需要取模 
        ans = ans * t % MOD;
    }
    cout << ans << endl;
    return 0;
}





