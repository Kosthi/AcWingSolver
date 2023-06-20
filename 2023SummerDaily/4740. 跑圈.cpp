#include <cstdio>
#include <cmath>

const int N = 10010;

typedef long long LL;

int T;
int L, n, s;
int d[N], c[N];
LL ans, pos;
char dir;

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d %d", &L, &n);
        pos = 0;
        ans = 0;
        while (n--) {
            scanf("%d %c", &s, &dir);
            if (dir == 'C') pos += s;
            else pos -= s;
            ans += abs(pos) / L;
            pos %= L;
        }
        printf("Case #%d: %lld\n", t + 1, ans);
    }
}
