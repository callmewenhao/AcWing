#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5+7;
const double eps = 1e-7;  // 实数二分精度
int n;
int a[N];
vector<double> ans;

// 必须使用 double
bool check(double r) {
    ans.clear();
    ans.push_back(a[0] + r);
    for (int i = 1; i < n; i++) {
        if (ans.back() + r < a[i]){
            if (ans.size() == 3) return false;
            ans.push_back(a[i] + r);
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);;
    sort(a, a+n);

    // 二分模板
    double l = 0., r = 5e8;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }

    // 这个操作挺玄学的
    check(r);

    // ans
    printf("%lf\n", l);
    while (ans.size() < 3) ans.push_back(0);
    for (auto t: ans) {
        printf("%lf ", t);
    }
    puts("");
    return 0;
}


