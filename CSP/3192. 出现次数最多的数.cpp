#include <cstdio>

const int N = 1010, M = 10010;

int n, k;
int h[M];
int minx, ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        h[k]++;
    }
    for (int i = 1; i <= M; ++i) {
        if (minx < h[i]) {
            minx = h[i];
            ans = i;
        }
    }
    printf("%d", ans);
}
