#include <iostream>

using namespace std;

string s1, s2, tmp1, tmp2;

int main() {
    cin >> s1 >> s2;
    for (int i = 1; i < s1.size(); ++i) {
        if (s1[i] % 2 == s1[i - 1] % 2) {
            tmp1 += max(s1[i], s1[i - 1]);
        }
    }
    for (int i = 1; i < s2.size(); ++i) {
        if (s2[i] % 2 == s2[i - 1] % 2) {
            tmp2 += max(s2[i], s2[i - 1]);
        }
    }
    if (tmp1 == tmp2) cout << tmp1 << endl;
    else cout << tmp1 << endl << tmp2 << endl;
}
