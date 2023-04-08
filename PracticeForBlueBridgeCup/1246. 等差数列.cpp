#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N];

int gcd(int m, int n) {
    return n ? gcd(n, m % n) : m;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    int d = 0;
    for (int i = 1; i < n; ++i) d = gcd(d, a[i] - a[0]);
    if (!d) printf("%d", n);
    else printf("%d", (a[n - 1] - a[0]) / d + 1);
}
