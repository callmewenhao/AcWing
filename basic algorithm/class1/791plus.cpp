/**
 * 高精度加法
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> add(vector<int>& A, vector<int>& B) {
    vector<int> C;

    int crray = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        int sum = crray;
        if (i < A.size())
            sum += A[i];
        if (i < B.size())
            sum += B[i];
        C.push_back(sum % 10);
        crray = sum / 10;
    }
    if (crray)
        C.push_back(crray);
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

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    cout << endl;
    return 0;
}
