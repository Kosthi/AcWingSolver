#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

double n;

int main() {
    cin >> n;
    double l = -10000, r = 100000;
    while (r - l > 1e-7) {
        double mid = (l + r) / 2.0;
        if (mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%.6lf", r);
}
