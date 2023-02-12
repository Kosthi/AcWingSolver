#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 100010;

typedef long long LL;

int n, s[N], cnt;
LL res;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    
    if (!(s[n] % 3)) {
        for (int i = 3; i <= n; ++i) {
            if (s[i - 2] == s[n] / 3) cnt++;
            if (s[n] - s[i - 1] == s[n] / 3) res += cnt;
        }
    }
    printf("%lld", res);
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 100010;

typedef long long LL;

int n, s[N], cnt;
LL res;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    
    if (!(s[n] % 3)) {
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[n] / 3 * 2) res += cnt;
            if (s[i] == s[n] / 3) cnt++;
        }
    }
    printf("%lld", res);
}
