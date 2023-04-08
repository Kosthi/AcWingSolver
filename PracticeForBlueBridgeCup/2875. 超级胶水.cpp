#include <cstdio>
#include <cstring>

const int N = 100010;

typedef long long LL;

int n;
LL sum, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; ++i) {
        sum += a[i] * a[i + 1];
        a[i + 1] += a[i];
    }
    printf("%lld", sum);
}

