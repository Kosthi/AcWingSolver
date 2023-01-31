// 朴素dp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int f[N][N];
int v[N], w[N];


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &v[i], &w[i]);
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    printf("%d", f[n][m]);
}

// 优化dp 从大到小循环实现状态滞后
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int f[N];
int v[N], w[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &v[i], &w[i]);
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= v[i]; --j) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    
    printf("%d", f[m]);
}

// 边读边算
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v, w;
int f[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &v, &w);
        for (int j = m; j >= v; --j)
            f[j] = max(f[j], f[j - v] + w);
    }
    printf("%d", f[m]);
}
