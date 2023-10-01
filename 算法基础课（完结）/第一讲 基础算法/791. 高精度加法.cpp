/**
 * 高精度加法
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 1e5+10;

vector<int> add(vector<int>& A, vector<int>& B) {
    vector<int> C; // 答案
    int t = 0; // 进位
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);  // 结果
        t /= 10; // 更新进位
    }
    if (t) C.push_back(t);  // 最后判断是否进位
    return C;
}

int main() {
    // 大数
    string a, b;
    cin >> a >> b;

    // 从个位开始存大数
    vector<int> A(a.size()), B(b.size());
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0'); 
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0'); 

    // 高精度加法
    auto C = add(A, B);

    // 输出答案 从高位开始
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

    return 0;
}
