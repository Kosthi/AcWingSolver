#include <cstdio>

const int N = 100010;

int n, k;
int h[N], w[N];

bool check(int e) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (h[i] / e) * (w[i] / e);
    }
    if (sum >= k) return true;
    return false;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d %d", &h[i], &w[i]);
    int l = 1, r = N;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%d", r);
}
