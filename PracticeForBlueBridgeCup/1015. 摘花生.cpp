// 二维dp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int T;
int r, c;
int a[N][N], f[N][N];


int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &r, &c);
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                scanf("%d", &a[i][j]);
                f[i][j] = max(f[i][j - 1], f[i - 1][j]) + a[i][j];
            }
        }
        printf("%d\n", f[r][c]);
    }
}

// 动态数组优化
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int T;
int r, c, n;
int f[N];


int main() {
    scanf("%d", &T);
    while (T--) {
        memset(f, 0, sizeof f);
        scanf("%d %d", &r, &c);
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                scanf("%d", &n);
                f[j] = max(f[j], f[j - 1]) + n;
            }
        }
        printf("%d\n", f[c]);
    }
}
