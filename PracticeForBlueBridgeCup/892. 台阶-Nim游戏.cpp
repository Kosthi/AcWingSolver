#include <cstdio>

int n, k, ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        if (i % 2) ans ^= k;
    }
    if (ans) puts("Yes");
    else puts("No");
}
