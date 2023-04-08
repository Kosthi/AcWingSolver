#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 200010;

int a[N];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m + 1; ++i) scanf("%d", &a[i]);
    sort(a, a + n + m + 1);
    LL ans = 0;
    if (!m) {
        for (int i = 0; i < n + m + 1; ++i) ans += a[i];
    }
    else {
        ans = a[n + m] - a[0];
        for (int i = 1; i < n + m; ++i) ans += abs(a[i]);
    }
    printf("%lld", ans);
}
