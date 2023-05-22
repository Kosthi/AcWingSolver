#include <cstdio>

const int N = 100, M = 20;

int n, b;
int s[N];
bool col[M], dg[M], udg[M]; 
int cnt;

void dfs(int u, int way) {
    if (u > 8) {
        s[++cnt] = way;
        return;
    }
    for (int i = 1; i <= 8; ++i) {
        if (!col[i] && !dg[8 + u - i] && !udg[u + i]) {
            col[i] = dg[8 + u - i] = udg[u + i] = true;
            dfs(u + 1, way * 10 + i);
            col[i] = dg[8 + u - i] = udg[u + i] = false;
        }
    }
}

int main() {
    dfs(1, 0);
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &b);
        printf("%d\n", s[b]);
    }
}
