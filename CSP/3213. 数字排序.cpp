#include <cstdio>
#include <algorithm>
#include <iostream>

const int N = 1010;

int n;
int a[N];

struct H {
    int n, cnt;
    bool operator<(const H& h) const {
        if (cnt == h.cnt) return n < h.n;
        return cnt > h.cnt;
    }
}h[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        h[a[i]].cnt++, h[a[i]].n = a[i];
    }
    std::sort(h, h + N);
    for (int i = 0; i < N; ++i) {
        if (h[i].cnt != 0) printf("%d %d\n", h[i].n, h[i].cnt);
    }
}
