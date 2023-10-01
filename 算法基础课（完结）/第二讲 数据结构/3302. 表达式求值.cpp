/**
 * 表达式求值 一个可扩展的运算符模板
 * 
 * 栈模板 使用双栈模拟表达式求值过程
 * 
 * 一个栈 num 存放遍历到的数字、另一个 op 存放遍历到的运算符（运算之间有优先级）
 * 
 * eval 函数则是使用 当前栈顶的两个数字 和 一个运算符 计算结果
 * 为了保证结果准确，op 中的运算符优先级必须是升序的 比如：a+b*c 而不是 a*b+c
 * 
 * 当我们遇到 优先级低于 op 栈顶的运算符时 我们就要使用 eval 计算值，直到 优先级 满足要求
 * 
 * 括号单独处理即可，把括号内的表达式求值 
 * 
 * 最后，使用 eval 计算 op 中剩余的运算
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num;
stack<char> op;

// 把当前的 两个数 和 一个操作符 运算一下 结果放入 num
void eval() {
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();
    char c = op.top(); op.pop();

    int res;
    if (c == '+') res = a + b;
    else if (c == '-') res = a - b;
    else if (c == '*') res = a * b;
    else if (c == '/') res = a / b;
    num.push(res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    // 运算符优先级
    unordered_map<char, int> pr = {
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2},
    };

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        
        if (isdigit(s[i])) {  // 数字
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j])) {
                x = 10 * x + s[j] - '0';
                j++;
            }
            num.push(x);
            i = j - 1;
        } else if (s[i] == '(') {  // '('
            op.push('(');
        } else if (s[i] == ')') {  // ')'
            while (op.top() != '(') {
                eval();
            }
            op.pop();
        } else {  // 优先级
            while (!op.empty() && op.top() != '(' && pr[s[i]] <= pr[op.top()]) {
                eval();
            }
            op.push(s[i]);
        }
    }
    
    // 剩余表达式
    while (!op.empty()) {
        eval();
    }

    cout << num.top() << endl;
    return 0;
}