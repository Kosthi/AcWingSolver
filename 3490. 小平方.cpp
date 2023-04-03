#include <cstdio>

int n, cnt;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; ++i) {
        if (i * i % n < (n + 1) / 2) cnt++;
    }
    printf("%d", cnt);
}
