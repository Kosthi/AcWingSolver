#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000100;

int n, m;
int w[N];

struct Node {
    int l, r;
    int maxv;
}tr[4 * N];


void pushup(int u) {
    tr[u].maxv = max(tr[u << 1].maxv, tr[u << 1 | 1].maxv);
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, w[r]};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].maxv;
    int mid = tr[u].l + tr[u].r >> 1;
    int maxv = INT32_MIN;
    if (l <= mid) maxv = query(u << 1, l, r);
    if (r > mid) maxv = max(maxv, query(u << 1 | 1, l, r));
    return maxv;
}

void modify(int u, int x, int v) {
    if (tr[u].l == tr[u].r) tr[u].maxv += v;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
    build(1, 1, n);
    
    int x, y;
    while (m--) {
        scanf("%d %d", &x, &y);
        printf("%d\n", query(1, x, y));
    }
}
