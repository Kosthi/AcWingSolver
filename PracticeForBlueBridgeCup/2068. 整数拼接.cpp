#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int N = 100010;

typedef long long LL;

LL a[N], s[11][N];
int n, k;
LL ans;

int main() {
    scanf("%lld %lld", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        int tmp = a[i] % k;
        for (int j = 0; j < 11; ++j) {
            s[j][tmp]++;
            tmp = tmp * 10 % k;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        int tmp = a[i] % k;
        int len = to_string(a[i]).size();
        ans += s[len][(k - tmp) % k];
        
        while (len--) a[i] = a[i] * 10 % k;
        if (a[i] == (k - tmp) % k) ans--;
    }
    printf("%lld", ans);
}
