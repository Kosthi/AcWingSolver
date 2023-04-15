/* 坑点1：字符串的读取
 * 坑点2：边读边建推, 顺序插入
 * 坑点3：负号的读取
 * 坑点4：getline(), getchar()
*/

#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int h[N];

void up(int u) {
    if (u / 2 && h[u / 2] > h[u]) {
        swap(h[u / 2], h[u]);
        up(u / 2);
    }
}

int check(string s) {
    if (s[s.size() - 1] == 't') return 1;
    if (s[s.size() - 1] == 's') return 2;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'p') return 3;
        if (s[i] == 'c') return 4;
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        up(i);
    }
    getchar();
    string s;
    while (m--) {
        s.clear();
        getline(cin, s);
        int k = check(s);
        if (k == 1) {
            int op = 1;
            int ans = 0;
            for (int i = 0, f = 0; i < s.size(); ++i) {
                if (s[i] >= '0' && s[i] <= '9') {
                    if (s[i - 1] == '-') op = -1;
                    ans = ans * 10 + s[i] - '0';
                    f = 1;
                }
                else if (f) break;
            }
            if (op * ans == h[1]) cout << "T" << endl;
            else cout << "F" << endl;
        }
        else if (k == 2) {
            int op = 1;
            int x = 0, y = 0, i, f;
            for (i = 0, f = 0; i < s.size(); ++i) {
                if (s[i] >= '0' && s[i] <= '9') {
                    if (s[i - 1] == '-') op = -1;
                    x = x * 10 + s[i] - '0';
                    f = 1;
                }
                else if (f) break;
            }
            x *= op;
            op = 1;
            for (f = 0; i < s.size(); ++i) {
                if (s[i] >= '0' && s[i] <= '9') {
                    if (s[i - 1] == '-') op = -1;
                    y = y * 10 + s[i] - '0';
                    f = 1;
                }
                else if (f) break;
            }
            y *= op;
            for (int i = 1; i <= n; ++i) {
                if (i % 2 == 0 && (h[i] == x && h[i + 1] == y || h[i] == y && h[i + 1] == x)) {
                    cout << "T" << endl;
                    break;
                }
                if (i == n) cout << "F" << endl;
            }
        }
        else if (k == 3) {
            int x = 0, y = 0, i, f;
            int op = 1;
            for (i = 0, f = 0; i < s.size(); ++i) {
                if (s[i] >= '0' && s[i] <= '9') {
                    if (s[i - 1] == '-') op = -1;
                    x = x * 10 + s[i] - '0';
                    f = 1;
                }
                else if (f) break;
            }
            x *= op;
            op = 1;
            for (f = 0; i < s.size(); ++i) {
                if (s[i] >= '0' && s[i] <= '9') {
                    if (s[i - 1] == '-') op = -1;
                    y = y * 10 + s[i] - '0';
                    f = 1;
                }
                else if (f) break;
            }
            y *= op;
            for (int i = 1; i <= n; ++i) {
                if (x <= y && h[i] == y && h[i / 2] == x) {
                    cout << "T" << endl;
                    break;
                }
                if (i == n) cout << "F" << endl;
            }
        }
        else if (k == 4) {
            int x = 0, y = 0, i, f;
            int op = 1;
            for (i = 0, f = 0; i < s.size(); ++i) {
                if (s[i] >= '0' && s[i] <= '9') {
                    if (s[i - 1] == '-') op = -1;
                    x = x * 10 + s[i] - '0';
                    f = 1;
                }
                else if (f) break;
            }
            x *= op;
            op = 1;
            for (f = 0; i < s.size(); ++i) {
                if (s[i] >= '0' && s[i] <= '9') {
                    if (s[i - 1] == '-') op = -1;
                    y = y * 10 + s[i] - '0';
                    f = 1;
                }
                else if (f) break;
            }
            y *= op;
            for (int i = 1; i <= n; ++i) {
                if (y <= x && h[i] == x && h[i / 2] == y) {
                    cout << "T" << endl;
                    break;
                }
                if (i == n) cout << "F" << endl;
            }
        }
    }
}
