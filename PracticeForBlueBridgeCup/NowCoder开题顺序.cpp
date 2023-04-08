#include <cstdio>
#include <iostream>

const int N = 10;

typedef long long LL;

int n, t, p;
int a[N], b[N], c[N], x[N], y[N];
LL ans;
int st[10];

void dfs(int u, LL s, int time) {
    if (u >= n) {
        ans = std::max(ans, s);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!st[i]) {
            if (time + x[i] <= t) {
                st[i] = 1;
                dfs(u + 1, s + std::max(c[i], a[i] - (time + x[i]) * b[i] - y[i] * p), time + x[i]);
                st[i] = 0;
            }
            else {
                ans = std::max(ans, s);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &t, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d %d %d %d", &a[i], &b[i], &c[i], &x[i], &y[i]);
    for (int i = 1; i <= n; ++i) {
        st[i] = 1;
        dfs(1, std::max(c[i], a[i] - x[i] * b[i] - y[i] * p), x[i]);
        st[i] = 0;
    }
    printf("%lld", ans);
}
