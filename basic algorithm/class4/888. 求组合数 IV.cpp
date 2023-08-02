/**
 * 组合数 4
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
const int N = 5010;

int primes[N], cnt;
int sum[N];
int st[N];

int get_primes(int n) {
    // 线性筛素数
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

// 计算 n! 中的 p 的个数
int get(int n, int p) {
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
} 

vector<int> mul(vector<int> a, int b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10; 
    }

    while (t) {
        c.push_back(t % 10);
        t /= 10;
    }

    return c;
}

int main() {
    int a, b;
    cin >> a >> b;

    // 筛质数
    get_primes(a);  // 因为 a > b 所以筛 a

    // 计算每一个质数的次数
    for (int i = 0; i < cnt; i++) {
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a-b, p);
        
        // cout << primes[i] << " " << sum[i] << endl;
    }

    // 使用高精度乘法计算最终结果
    vector<int> res;
    res.push_back(1);
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < sum[i]; j++) {
            res = mul(res, primes[i]);
            
        }
    }

    // 输出答案
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
    cout << endl;

    return 0;
}

