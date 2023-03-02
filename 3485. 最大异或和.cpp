#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 3000010;

int s[N];
int n, m, res;
int son[M][2], cnt[M], idx;

void insert(int x, int v) {
    int p = 0;
    for (int i = 30; ~i; --i) {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p] += v;
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; ~i; --i) {
        int u = x >> 30 & 1;
        if (cnt[son[p][!u]]) {
            p = son[p][!u];
            res = 2 * res + 1;
        }
        else {
            p = son[p][u];
            res = 2 * res;
        }
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
        s[i] = s[i - 1] ^ s[i];
    }
    
    insert(s[0], 1);
    for (int i = 1; i <= n; ++i) {
        if (i - m - 1 >= 0 ) insert(s[i - m - 1], -1);
        res = max(res, query(s[i]));
        insert(s[i], 1);
    }
    cout << res << endl;
}
