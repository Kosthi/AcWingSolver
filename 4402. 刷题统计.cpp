#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;

LL cnt;
LL a, b, n;

int main() {
    scanf("%lld %lld %lld", &a, &b, &n);
    cnt = n / (5 * a + 2 * b) * 7;
    n %= 5 * a + 2 * b;
    for (int i = 0; i < 5 && n > 0; ++i, ++cnt) n -= a;
    for (int i = 0; i < 2 && n > 0; ++i, ++cnt) n -= b; 
    printf("%lld", cnt);
}
