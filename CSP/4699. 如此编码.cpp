#include <cstdio>

const int N = 30;

int n, m;
int a[N], b[N], c[N];

int main() {
    c[0] = 1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        c[i] = c[i - 1] * a[i];
    }
    for (int i = 1; i <= n; ++i) b[i] = (m % c[i] - m % c[i - 1]) / c[i - 1];
    for (int i = 1; i <= n; ++i) printf("%d ", b[i]);
}
