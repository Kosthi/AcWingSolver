#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<char> s;
queue<char> q[2010];
int n, m, smax;
char c;

int main() {
    cin >> n >> m >> smax;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c;
            q[i].push(c);
        }
    }
    int op;
    while (cin >> op && op != -1) {
        if (op == 0) {
            if (s.size()) {
                cout << s.top();
                s.pop();
            }
        }
        else {
            if (q[op].size()) {
                if (s.size() == smax) {
                    cout << s.top();
                    s.pop();
                }
                s.push(q[op].front());
                q[op].pop();
            }
        }
    }
}
