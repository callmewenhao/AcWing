#include <iostream>
#include <queue>

using namespace std;
using LL = long long;
using PIL = pair<LL, int>;

const int N = 5e5+7;

int n, k;
LL l[N];
priority_queue<PIL, vector<PIL>, greater<>> q;

int main() {

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int s, t;
        cin >> s >> t;

        if (q.size() < k) {
            l[i] = (LL)s + t;
            q.push({l[i], i});
        } else {
            auto [t_top, _] = q.top();
            q.pop();
            if (s >= t_top) l[i] = s + t;
            else l[i] = t_top + t;
            q.push({l[i], i});
        }
        cout << l[i] << endl;
    }

    return 0;
}




