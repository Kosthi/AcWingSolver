#include <cstdio>
#include <cstring>

typedef long long LL;
LL n;

int main() {
    scanf("%lld", &n);
    for (; n; n /= 2) printf("%lld ", n);
}
