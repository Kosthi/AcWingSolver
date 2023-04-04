#include <cstdio>
#include <cstring>

double n;

int main() {
    scanf("%lf", &n);
    double l = -10000, r = 10000;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid <= n) l = mid;
        else r = mid;
    }
    printf("%.6lf", r);
}
