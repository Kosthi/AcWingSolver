// 证明Cn2 + n == Cn+1 2
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define LL long long

using namespace std;

const int N = 1e6;

int n, k, cnt[N];
LL res;
LL s[N];


int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
        s[i] = (s[i - 1] + s[i]) % k;
        res += cnt[s[i]];
        cnt[s[i]]++;
    }
    printf("%lld", res + cnt[0]);
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define LL long long

using namespace std;

const int N = 1e6;

int n, k, cnt[N];
LL res;
LL s[N];


int main() {
    scanf("%d %d", &n, &k);
    cnt[0] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
        s[i] = (s[i - 1] + s[i]) % k;
        res += cnt[s[i]];
        cnt[s[i]]++;
    }
    printf("%lld", res);
}

// Cn2公式
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define LL long long

using namespace std;

const int N = 1e6;

int n, k;
LL cnt[N];
LL res;
LL s[N];


int main() {
    scanf("%d %d", &n, &k);
    cnt[0] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
        s[i] = (s[i - 1] + s[i]) % k;
        cnt[s[i]]++;
    }
    for (int i = 0; i < k; ++i) {
        res += cnt[i] * (cnt[i] - 1) / 2;
    }
    printf("%lld", res);
}
