#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int n, st[N];

void dfs(int u, int v) {
    if (u > n) {
        string s;
        while (v) {
            int k = v % 10;
            s += ' ';
            s += k + '0';
            v /= 10;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!st[i]) {
            st[i] = 1;
            dfs(u + 1, v * 10 + i);
            st[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1, 0);
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int n, st[N], used[N];

void dfs(int u) {
    if (u > n) {
        for (int i = 1; i <= n; ++i) {
            cout << st[i] << " ";
        }
        puts("");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            st[u] = i;
            used[i] = 1;
            dfs(u + 1);
            used[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
}
