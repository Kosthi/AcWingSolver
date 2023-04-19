#include <cstdio>

const int N = 1010, M = 998244353;

typedef long long LL;

int n, m, A, B;
int w[N][N], q[N];
int rmax[N][N], rmin[N][N];
int sum;

int get_max(int a[], int b[], int tot, int k) {
    int hh = 0, tt = -1;
    for (int i = 0; i < tot; ++i) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}

int get_min(int a[], int b[], int tot, int k) {
    int hh = 0, tt = -1;
    for (int i = 0; i < tot; ++i) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &A, &B);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &w[i][j]);
        }
    }
    
    // 每行B区间最值
    for (int i = 0; i < n; ++i) {
        get_max(w[i], rmax[i], m, B);
        get_min(w[i], rmin[i], m, B);
    }
    
    int a[N], b[N], c[N];
    // 每rmax/min A区间最值
    for (int i = B - 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) a[j] = rmax[j][i];
        get_max(a, b, n, A);
        for (int j = 0; j < n; ++j) a[j] = rmin[j][i];
        get_min(a, c, n, A);
        for (int j = A - 1; j < n; ++j)
            sum = (sum + (LL)b[j] * c[j]) % M;
    }
    printf("%d", sum);
}
