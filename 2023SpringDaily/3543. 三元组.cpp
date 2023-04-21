#include <cstdio>

const int N = 100;

int n, m;
int a[N], st[N], cnt;

void dfs(int u, int s) {
    if (u >= 2) {
        for (int i = 0; i < m; ++i) {
            if (s == a[i]) cnt++;
        }
        return;
    }
    for (int i = 0; i < m; ++i) {
        dfs(u + 1, s + a[i]);
    }
}

int main() {
    scanf("%d", &n);
     while (n--) {
         scanf("%d", &m);
         for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
         cnt = 0;
         dfs(0, 0);
         printf("%d\n", cnt);
     }
}
