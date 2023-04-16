#include <iostream>
#include <string>

using namespace std;

const int N = 40;

string s[N], ans;
int n, m;

bool check(string s) {
    if (s.find("qiandao") == -1 && s.find("easy") == -1) return 1;
    return 0;
}

int main() {
    cin >> n >> m;
    getchar();
    for (int i = 0; i < n; ++i) getline(cin, s[i]);
    for (int i = 0; i < n; ++i) {
        if (check(s[i]) && m + 1) ans = s[i], m--;
        if (i == n - 1) {
            if (m == -1) cout << ans << endl;
            else cout << "Wo AK le" << endl;
        }
    }
}
