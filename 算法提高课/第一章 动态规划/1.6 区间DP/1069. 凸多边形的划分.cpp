#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 55, M = 35, INF = 1e9;

int n;
int w[N];
LL f[N][N][M];

void add(LL a[], LL b[])
{
    static LL c[M];
    memset(c, 0, sizeof c);
    for (int i = 0, t = 0; i < M; i ++ )
    {
        t += a[i] + b[i];
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}

void mul(LL a[], LL b)
{
    static LL c[M];
    memset(c, 0, sizeof c);
    LL t = 0;
    for (int i = 0; i < M; i ++ )
    {
        t += a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}

int cmp(LL a[], LL b[])
{
    for (int i = M - 1; i >= 0; i -- )
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    return 0;
}

void print(LL a[])
{
    int k = M - 1;
    while (k && !a[k]) k -- ;
    while (k >= 0) cout << a[k -- ];
    cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];

    LL temp[M];
    for (int len = 3; len <= n; len ++ )
        for (int l = 1; l + len - 1 <= n; l ++ )
        {
            int r = l + len - 1;
            f[l][r][M - 1] = 1;
            for (int k = l + 1; k < r; k ++ )
            {
                memset(temp, 0, sizeof temp);
                temp[0] = w[l];
                mul(temp, w[k]);
                mul(temp, w[r]);
                add(temp, f[l][k]);
                add(temp, f[k][r]);
                if (cmp(f[l][r], temp) > 0)
                    memcpy(f[l][r], temp, sizeof temp);
            }
        }

    print(f[1][n]);

    return 0;
}














 