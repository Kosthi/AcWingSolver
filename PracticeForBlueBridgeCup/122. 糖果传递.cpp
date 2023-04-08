#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;

typedef long long LL;

int a[N], c[N], n;
LL sum;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    
    LL avg = sum / n;
    
    for (int i = n - 1; ~i; --i) {
        c[i] = c[i + 1] + avg - a[i];
    }
    sort(c, c + n);
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += abs(c[i] - c[n / 2]);
    }
    printf("%lld", sum);
}
