/**
 * 高精度减法
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//A >= B ? 
bool cmp(vector<int>& A, vector<int>& B) {
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--) {  // 由高位向低位遍历
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}

// 减法 len(A) >= len(B)
vector<int> sub(vector<int>& A, vector<int>& B) {
    vector<int> C;

    int lend = 0;
    for (int i = 0; i < A.size(); i++) {
        lend = A[i] - lend;
        if (i < B.size())
            lend -= B[i];
        C.push_back((lend + 10) % 10);

        if (lend < 0)
            lend = 1;
        else
            lend = 0;
    }
    // 去掉前导零
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }
    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    vector<int> A(a.size()), B(b.size());
    for (int i = a.size() - 1, j = 0; i >= 0; i--, j++) {
        A[j] = a[i] - '0';
    }
    for (int i = b.size() - 1, j = 0; i >= 0; i--, j++) {
        B[j] = b[i] - '0';
    }
    if (cmp(A, B)) {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--) {
            cout << C[i];
        }
    } else {
        cout << "-";
        auto C = sub(B, A);
        for (int i = C.size() - 1; i >= 0; i--) {
            cout << C[i];
        }
    }
    cout << endl;
    return 0;
}