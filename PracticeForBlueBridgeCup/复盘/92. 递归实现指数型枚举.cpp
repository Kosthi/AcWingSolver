#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int n, st[N];

void dfs(int u) {
    if (u > n) {
        for (int i = 1; i <= n; ++i) {
            if (st[i]) cout << i << " ";
        }
        puts("");
        return;
    }
    dfs(u + 1);
    st[u] = 1;
    dfs(u + 1);
    st[u] = 0;
}

int main() {
    cin >> n;
    dfs(1);
}
