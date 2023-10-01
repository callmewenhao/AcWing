#include <iostream>
#include <cstring>
#include <map>

using namespace std;

using LL = long long;  

LL r, x0, y0, x1, y1;
map<pair<LL, LL>, LL> s;

LL dfs(LL dx, LL dy) {
    if (s.count({dx, dy})) return s[{dx, dy}];
    if (dx < 0 || dy < 0) return 1e10;
    if (dx == 0 && dy == 0) {
        s[{0, 0}] = 0;
        return 0;
    }

    LL res = 1e10;
    res = min(res, dfs(dx-1, dy-1) + 1);
    res = min(res, dfs(dx-2, dy) + 1);
    res = min(res, dfs(dx, dy-2) + 1);
    s[{dx, dy}] = res;
    return res;
}

int main() {

    cin >> r >> x0 >> y0 >> x1 >> y1;

    LL dx = abs(x0 - x1), dy = abs(y0 - y1);

    LL res = dfs(dx, dy);

    cout << res << endl;

    return 0;
}










