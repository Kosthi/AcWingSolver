#include <cstdio>
#include <cstring>

const int N = 100010;

typedef long long LL;

int n, m, l, r;
LL s[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }
    
    while (m--) {
        scanf("%d %d", &l, &r);
        printf("%lld\n", s[r] - s[l - 1]);
    }
}
