#include <iostream>
#include <queue>

using namespace std;

int n;

int main() {

    cin >> n;
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }

    int res = 0;
    // 下述过程确实是 哈夫曼树 的生成过程
    while (q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();

        res += a + b;
        q.push(a + b);
    }   

    cout << res << endl;

    return 0;
}



