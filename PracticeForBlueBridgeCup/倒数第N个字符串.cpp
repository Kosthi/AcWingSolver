#include <iostream>
#include <cmath>

using namespace std;

string s;
int L, N, k;

int main() {
    cin >> L >> N;
    int p = pow(26, L) - N;
    while (L--) {
        int k = p % 26;
        s += 'a' + k;
        p /= 26;
    }
    for (int i = s.size() - 1; i >= 0; --i) cout << s[i];
}
