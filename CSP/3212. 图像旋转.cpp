#include <cstdio>

const int N = 1010;

int n, m;
int a[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    for (int i = m - 1; ~i; --i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", a[j][i]);
        }
        puts("");
    }
}
