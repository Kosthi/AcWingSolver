#include <cstdio>
#include <cmath>

const int N = 1010;

int n, k;
int h[N];
int cnt;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        h[abs(k)]++;
    }
    for (int i = 1; i < N; ++i) if (h[i] == 2) cnt++;
    printf("%d", cnt);
}
