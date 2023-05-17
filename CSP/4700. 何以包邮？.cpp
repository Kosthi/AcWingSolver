#include <cstdio>
#include <iostream>

const int N = 40, M = 300010;

int n, m, v[N];
int s, f[M];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
        s += v[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = s - m; j >= v[i]; --j) {
            f[j] = std::max(f[j], f[j - v[i]] + v[i]);
        }
    }
    printf("%d", s - f[s - m]);
}
