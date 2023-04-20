#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1010;

int w[N][N];
int a, b, n;
int rmin[N][N], rmax[N][N], q[N];
int res = INT32_MAX;

void get_max(int a[], int b[], int tot, int k) {
    int hh = 0, tt = -1;
    for (int i = 0; i < tot; ++i) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}

void get_min(int a[], int b[], int tot, int k) {
    int hh = 0, tt = -1;
    for (int i = 0; i < tot; ++i) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}

int main() {
    scanf("%d %d %d", &a, &b, &n);
    
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            scanf("%d", &w[i][j]);
        }
    }
    
    for (int i = 0; i < a; ++i) {
        get_max(w[i], rmax[i], b, n);
        get_min(w[i], rmin[i], b, n);
    }
    
    int aa[N], bb[N], cc[N];
    for (int i = n - 1; i < b; ++i) {
        for (int j = 0; j < a; ++j) aa[j] = rmax[j][i];
        get_max(aa, bb, a, n);
        for (int j = 0; j < a; ++j) aa[j] = rmin[j][i];
        get_min(aa, cc, a, n);
        for (int j = n - 1; j < a; ++j) res = min(res, bb[j] - cc[j]);
    }
    printf("%d", res);
}
