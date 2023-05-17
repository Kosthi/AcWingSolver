#include <cstdio>
#include <cmath>

const int N = 1010;

int n;
double a[N], avg, da;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &a[i]);
        avg += a[i] / n;
    }
    double s = 0;
    for (int i = 0; i < n; ++i) {
        s += (a[i] - avg) * (a[i] - avg);
    }
    s /= n;
    for (int i = 0; i < n; ++i) {
        printf("%.16lf\n", (a[i] - avg) / sqrt(s));
    }
}
