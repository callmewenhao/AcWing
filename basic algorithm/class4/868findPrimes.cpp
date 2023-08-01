/**
 * 筛质数
 */

#include <iostream>

using namespace std;

const int N = 1e6 + 7;

int cnt, primes[N];
bool st[N]; // 不是质数

/*
// 埃氏筛
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            for (int j = 2 * i; j <= n; j += i) {
                st[j] = true;
            }
        }
    }
}
*/

// 线性筛
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        
        for (int j = 0; primes[j] <= n / i; j++) {
            // 保证使用最小质因子筛合数
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}


int main() {
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}
