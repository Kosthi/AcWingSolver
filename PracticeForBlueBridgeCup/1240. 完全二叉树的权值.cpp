#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 100010;

typedef long long LL;

int n;
int a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    
    int depth = 0;
    LL sum = INT64_MIN;
    for (int i = 0, d = 1; i < n; i += (1 << d - 1), d++) {
        LL s = 0;
        for (int j = i; j < i + (1 << d - 1) && j < n; ++j) s += a[j];
        if (s > sum) {
            sum = s;
            depth = d;
        }
    }
    printf("%d", depth);
}

#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 100010;

typedef long long LL;

int n;
LL a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    
    int depth = 0;
    LL sum = INT64_MIN;
    for (int i = 1, d = 1; i <= n; i += (1 << d - 1), d++) {
        LL s;
        if (i + (1 << d - 1) - 1 <= n)
            s = a[i + (1 << d - 1) - 1] - a[i - 1];
        else
            s = a[n] - a[i - 1];
        if (s > sum) {
            sum = s;
            depth = d;
        }
    }
    printf("%d", depth);
}
