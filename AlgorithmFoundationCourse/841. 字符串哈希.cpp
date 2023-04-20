#include <cstdio>

const int N = 100010, P = 131;

typedef unsigned long long ULL;

int n, m;
int l1, r1, l2, r2;
ULL h[N], p[N];
char s[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    scanf("%d %d %s", &n, &m, s + 1);
    
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i];
    }
    
    while (m--) {
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2)) printf("Yes\n");
        else printf("No\n");
    }
}
