#include <iostream>
#include <cstdio>

typedef long long LL;

const int N = 1010, M = 1000000007;

int T, n;
int a[N];
LL dp[N][2];
LL sum = 0;

int main() {
    scanf("%d", &T);
    while (T--) {
        sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        
        if (sum & 1 == 1) {
            puts("0");
            continue;
        }
        
        dp[0][0] = 1;
        dp[0][1] = 0;
        
        for (int i = 1; i <= n; ++i) {
            if ((a[i] & 1) == 0) {
                dp[i][0] = (dp[i - 1][0] << 1) % M;
                dp[i][1] = (dp[i - 1][1] << 1) % M;
            } else {
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % M;
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % M;
            }
        }
        
        printf("%lld\n", dp[n][0]);
    }
}

