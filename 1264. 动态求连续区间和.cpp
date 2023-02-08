#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 100010;

int n, m;
int a[N], tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (int i = x; i <= N; i += lowbit(i)) tr[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        add(i, a[i]);
    }
    while (m--) {
        int k, a, b;
        scanf("%d %d %d", &k, &a, &b);
        if (k) add(a, b);
        else printf("%d\n", query(b) - query(a -  1));
    }
}
