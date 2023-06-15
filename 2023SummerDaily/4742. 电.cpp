#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 200010;

int n, T;
int h[N], e[N], ne[N], w[N], idx;
int s[N];
int ans;
int a, b;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
    s[u] = 1;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!s[j]) s[j] = dfs(j);
        s[u] += s[j];
    }
    return s[u];
}

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        ans = 0;
        idx = 0;
        memset(h, -1, sizeof h);
        memset(e, 0, sizeof e);
        memset(ne, 0, sizeof ne);
        memset(s, 0, sizeof s);
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d %d", &a, &b);
            if (w[a] > w[b]) add(a, b);
            else if (w[b] > w[a]) add(b, a);
        }
        for (int i = 1; i <= n; ++i) {
            if (!s[i]) ans = std::max(ans, dfs(i));
            ans = std::max(ans, dfs(i));
        }
        printf("Case #%d: %d\n", t + 1, ans);
    }
}
