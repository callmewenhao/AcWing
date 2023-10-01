/*
下凸函数的最小值 三分答案
*/

#include <iostream>

using namespace std;

using LL = long long;

const int N = 2e5+7;

int n;

struct Person { 
    int p, w, d;
} P[N];

LL get_cost(int mid) {
    LL res = 0;
    for (auto [p, w, d]: P) {
        if (p - d <= mid && mid <= p + d) continue;
        if (mid < p) res += 1LL * (p - d - mid) * w;
        else res += 1LL * (mid - d - p) * w;
    }
    return res;
}

int main() {
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> P[i].p >> P[i].w >> P[i].d;
    }
    
    int l = 0, r = 1e9;
    while (l <= r) {
        int midl = l + (r-l) / 3;
        int midr = r - (r-l) / 3;
        if (get_cost(midl) <= get_cost(midr)) r = midr-1;
        else l = midl+1;
    }
    
    cout << min(get_cost(l), get_cost(r));
    
    return 0;
}