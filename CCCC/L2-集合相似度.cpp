#include <iostream>
#include <cstring>
#include <set>

using namespace std;

const int N = 100;

set<int> s[N];

int n, m;
int a, b;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        for (int j = 0, k; j < m; ++j) {
            cin >> k;
            s[i].insert(k);
        }
    }
    cin >> n;
    int ii, jj;
    while (n--) {
        cin >> ii >> jj;
        a = 0;
        for (set<int>::iterator it = s[ii].begin(); it != s[ii].end(); ++it)
            if (s[jj].count(*it)) a++;
        b = s[ii].size() + s[jj].size() - a;
        printf("%.2f%%\n", (double)a / b * 100);
    }
}
