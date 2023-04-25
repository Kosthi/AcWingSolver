#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a, b;

string add(string& a, string& b) {
    string c;
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size(); ++i) {
        if (i < a.size()) t += a[i] - '0';
        if (i < b.size()) t += b[i] - '0';
        c.push_back(t % 10 + '0');
        t /= 10;
    }
    if (t) c.push_back('1');
    while (c.size() > 1 && c.back() == '0') c.pop_back();
    return c;
}

int main() {
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string c = add(a, b);
    for (int i = c.size() - 1; i >= 0; --i) printf("%c", c[i]);
}
