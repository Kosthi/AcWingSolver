#include <cstdio>

const int N = 100010;

typedef long long LL;

int n, g;
int a[N];
LL ans;
int last = -1;

int main() {
    scanf("%d %d", &n, &g);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0, j = 0; j < n; ++j) {
        if (a[j] % g) {
            i = last + 1, last = j;
        }
        ans += j - i;
    }
    printf("%lld", ans);
}
