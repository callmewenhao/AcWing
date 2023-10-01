/*
@File    : 3321.cpp
@Author  : wenhao
@Time    : 2023/6/26 22:33
@LC      : 
*/
#include<bits/stdc++.h>
//#include <iostream>
//#include <algorithm>
//#include <utility>

using namespace std;

const int N = 1e5 + 10;
pair<int, int> A[N];

int main() {
    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        int n, x;
        scanf("%d %d", &n, &x);
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            A[i].first = (a + x - 1) / x;
            A[i].second = i + 1;
        }
        // 保持先后顺序
        sort(A, A+n);
        // output
        printf("Case #%d: ", cases);
        for (int i = 0; i < n; i++) {
            printf("%d ", A[i].second);
        }
        printf("\n");
    }
    return 0;
}

