#include <cstdio>

const int N = 200010;

typedef long long LL;

int n;
int s[N];
LL sum;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        sum += (LL)(s[i] - s[i - 1]) * (s[n] - s[i]);
    }
    printf("%lld", sum);
}
