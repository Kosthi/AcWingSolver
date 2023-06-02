#include <cstdio>

const int N = 10010;

int n;
int a[N];
int minx = N, maxx;
int ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        minx = N, maxx = 0;
        for (int j = i; j < n; ++j) {
        if (a[j] > maxx) maxx = a[j];
        if (a[j] < minx) minx = a[j];
        if (j - i == maxx - minx) ans++;
        }
    }
    printf("%d", ans);
}
