/**
 * 
 * 由于时间限制是 2s
 * 所以一个 1e8 的算法也是可以的
 * 
*/
#include <iostream>
#include <string>

using namespace std;

const int N = 13, M = 1007;

int n, m;
string strs[M];
int f[N][N];

int get_res(string &a, string &b){
    int la = a.length(), lb = b.length();
    for (int i = 0; i <= la; i++) f[i][0] = i; 
    for (int j = 0; j <= lb; j++) f[0][j] = j; 

    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            f[i][j] = min(f[i-1][j-1] + int(a[i-1] != b[j-1]), min(f[i-1][j], f[i][j-1]) + 1);
        }
    }

    return f[la][lb];
}


int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> strs[i];
    }

    while (m--) {
        string str;
        int limit = 0;
        cin >> str >> limit;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int ops = get_res(str, strs[i]);
            if (ops <= limit) res++;
        }
        cout << res << endl;
    }
    return 0;
}






