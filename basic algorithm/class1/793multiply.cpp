/**
 * 高精度乘法
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> mul(vector<int>& A, int b) {
    vector<int> C;
    int carry = 0;
    for (int i = 0; i < A.size(); i++) {
        carry += A[i] * b;
        C.push_back(carry % 10);  // 个位
        carry /= 10; // 进位
    }
    while (carry) {
        C.push_back(carry % 10);
        carry /= 10;
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

    string a;
    int b;
    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }

    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    cout << endl;
    return 0;
}

