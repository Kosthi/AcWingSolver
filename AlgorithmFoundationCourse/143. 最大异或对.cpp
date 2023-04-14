#include <cstdio>
#include <iostream>

using namespace std;

const int N = 4000010, M = 100010;

int son[N][2], idx;

int n, k;
int a[M];

void insert(int w) {
    int p = 0;
    for (int i = 30; ~i; --i) {
        int k = w >> i & 1;
        if (!son[p][k]) son[p][k] = ++idx;
        p = son[p][k];
    }
}

int query() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int p = 0, res = 0;
        for (int j = 30; ~j; --j) {
            int k = a[i] >> j & 1;
            if (son[p][!k]) {
                res = res * 2 + 1;
                p = son[p][!k];
            }
            else {
                res *= 2;
                p = son[p][k];
            }
        }
        ans = max(ans, res);
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), insert(a[i]);
    printf("%d", query());
}
