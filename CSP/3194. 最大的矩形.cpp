#include <cstdio>

const int N = 1010;

int n;
int a[N];
int ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        int j, k;
        for (j = i - 1; j >= 0; --j) {
            if (a[j] < a[i]) break;
        }
        for (k = i + 1; k < n; ++k) {
            if (a[k] < a[i]) break;
        }
        if (ans < (k - j - 1) * a[i]) ans = (k - j - 1) * a[i];
    }
    printf("%d", ans);
}
