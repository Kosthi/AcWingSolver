#include <iostream>
#include <vector>

using namespace std;

string s1, s2;
vector<int> a, b;

vector<int> mul(vector<int>& a, vector<int>& b) {
    vector<int> c(a.size() + b.size());
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
            c[i + j] += a[i] * b[j];

    int t = 0;
    for (int i = 0; i < c.size(); ++i) {
        t += c[i];
        c[i] = t % 10;
        t /= 10;
    }
    
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main() {
    cin >> s1 >> s2;
    for (int i = s1.size() - 1; i >= 0; --i) a.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; --i) b.push_back(s2[i] - '0');
    auto c = mul(a, b);
    for (int i = c.size() - 1; i >= 0; --i) cout << c[i];
}
