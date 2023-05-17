// 背包dp
#include <cstdio>
#include <iostream>

const int N = 40, M = 300010;

int n, m, v[N];
int s, f[M];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
        s += v[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = s - m; j >= v[i]; --j) {
            f[j] = std::max(f[j], f[j - v[i]] + v[i]);
        }
    }
    printf("%d", s - f[s - m]);
}

// 剪枝DFS
#include <cstdio>
#include <iostream>
#include <algorithm>

const int N = 40;

int n, m, v[N];
int ans = 1e8, st[N];

void dfs(int u, int s) {
    if (s >= ans) return;
    int p = s;
    for (int i = u; i <= n; ++i) p += v[i];
    if (p < m) return;
    if (u > n) {
        if (s >= m && ans > s) ans = s;
        return;
    }
    dfs(u + 1, s);
    dfs(u + 1, s + v[u]);
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
    std::sort(v + 1, v + n + 1, cmp);
    dfs(1, 0);
    printf("%d", ans);
}
