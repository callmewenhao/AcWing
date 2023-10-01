#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

const int N = 1e5+10;

int x, y, n;
string X[N][2], Y[N][2];
unordered_map<string, int> cnt;

int p[3 * N];
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> X[i][0] >> X[i][1];
    }

    cin >> y;
    for (int i = 0; i < y; i++) {
        cin >> Y[i][0] >> Y[i][1];
    }

    int idx = 0;
    cin >> n;
    for (int i = 0; i < 3 * n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < n; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        cnt[a] = idx++;
        cnt[b] = idx++;
        cnt[c] = idx++;

        p[find(cnt[b])] = find(cnt[a]);
        p[find(cnt[c])] = find(cnt[a]);
    }

    int res = 0;
    for (int i = 0; i < x; i++) {
        string a = X[i][0], b = X[i][1];
        if (find(cnt[a]) != find(cnt[b])) res++;
    }

    for (int i = 0; i < y; i++) {
        string a = Y[i][0], b = Y[i][1];
        if (find(cnt[a]) == find(cnt[b])) res++;
    }

    cout << res << endl;

    return 0;
}






