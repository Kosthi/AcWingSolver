#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long LL;

const int N = 1000010;
int n;
int tr[N], h[N], sum[N];

int lowbit(int x) {
    return x & -x;
}

int add(int x, int v) {
    for (int i = x; i <= N; i += lowbit(i)) tr[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
        h[i]++;
    }
    
    for (int i = 1; i <= n; ++i) {
        sum[i] = query(N) - query(h[i]);
        add(h[i], 1);
    }
    
    memset(tr, 0, sizeof tr);
    for (int i = n; i >= 1; --i) {
        sum[i] += query(h[i] - 1);
        add(h[i], 1);
    }
    
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (LL)sum[i] * (1 + sum[i]) / 2;
    }
    printf("%lld", ans);
}
