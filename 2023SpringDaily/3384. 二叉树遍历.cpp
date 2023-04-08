#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

string s;
stack<char> q;

int main() {
    cin >> s;
    // 子节点个数永远比父节点多1
    // 读到n - 1个#号即弹出了所有节点
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] != '#') q.push(s[i]);
        else {
            char p = q.top();
            q.pop();
            cout << p << " ";
        }
    }
}
