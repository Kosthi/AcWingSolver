#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 32100;

int n, x, y;
int tr[N], level[N];

int lowerbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (int i = x; i <= N; i += lowerbit(i)) tr[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowerbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &x, &y);
        level[query(++x)]++;
        add(x, 1);
    }
    for (int i = 0; i < n; ++i) printf("%d\n", level[i]);
}
