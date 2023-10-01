#include <iostream> 
#include <algorithm> 
#include <utility>
#include <climits>

using namespace std;

const int N = 5e4+7; 

int n;
pair<int, int> cows[N];

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, s;
        cin >> w >> s;
        // 按照 体重 + 能力值 从小到大排序
        cows[i] = {w + s, w};
    }

    sort(cows, cows + n);

    int res = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++) {
        int w = cows[i].second, s = cows[i].first - cows[i].second;
        res = max(res, sum - s);
        sum += w;
    }

    cout << res << endl;

    return 0;
}


