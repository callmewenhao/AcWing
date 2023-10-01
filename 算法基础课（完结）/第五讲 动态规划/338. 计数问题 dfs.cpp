#include <iostream>
#include <cstring>

using namespace std;


string a;
int n, t;
int cache[10][15];
int dfs(int i, int cnt, bool is_num, bool limit) {
    if (i == n) {
        if (is_num) return cnt;
        return t == 0;
    }
    
    if (is_num && !limit && cache[i][cnt] != -1) 
        return cache[i][cnt];

    int res = 0;
    
    if (!is_num) {
        res += dfs(i+1, cnt, false, false);
    }
    
    int low = is_num ? 0 : 1;
    int up = limit ? a[i] - '0' : 9;
    for (int j = low; j <= up; j++) {
        res += dfs(i+1, cnt + int(j == t), true, limit && j == up);
    }
    
    if (is_num && !limit) cache[i][cnt] = res;
    
    return res;
}

int main() {
    
    int x, y;
    while (cin >> x >> y, x || y) {
        if (x < y) swap(x, y);
        y--;
        for (int i = 0; i < 10; i++) {
            t = i;
            
            a = to_string(x);
            n = a.size();
            memset(cache, -1, sizeof cache);
            int r1 = dfs(0, 0, false, true);
            
            a = to_string(y);
            n = a.size();
            memset(cache, -1, sizeof cache);
            int r2 = dfs(0, 0, false, true);
            
            cout << r1 - r2 << " ";
        }

        cout << endl;
    }

    
    return 0;
}