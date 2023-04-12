#include <iostream>
#include <stack>

using namespace std;

int n, num;
char c;
stack<int> s1;
stack<char> s2;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        s1.push(num);
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> c;
        s2.push(c);
    }
    while (!s2.empty()) {
        int b = s1.top();
        s1.pop();
        int a = s1.top();
        s1.pop();
        char op = s2.top();
        s2.pop();
        if (op == '/') {
            if (b == 0) {
                printf("ERROR: %d/0\n", a);
                return 0;
            }
            s1.push(a / b);
        }
        else if (op == '*') s1.push(a * b);
        else if (op == '-') s1.push(a - b);
        else if (op == '+') s1.push(a + b);
    }
    cout << s1.top() << endl;
}
