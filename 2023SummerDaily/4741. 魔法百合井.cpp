#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

const int N = 100010;

int T;
int n;

int dp[N];

int main() {
    memset(dp, 0x3f3f3f3f, sizeof dp);
    dp[1] = 1;
    for (int i = 2; i < N; ++i) {
        dp[i] = std::min(dp[i], dp[i - 1] + 1);
        for (int k = 1; k <= sqrt(i); ++k) {
            if (i % k == 0) {
                dp[i] = std::min(dp[i], dp[i / k] + 4 + (k - 1) * 2);
            }
        }
    }
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k) {
        scanf("%d", &n);
        printf("Case #%d: %d\n", k, dp[n]);
    }
}

#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 100010;

int T;
int n;

int dp[N];

int main() {
    memset(dp, 0x3f3f3f3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        dp[i] = std::min(dp[i], dp[i - 1] + 1);
        for (int j = 2; i * j <= N; ++j) {
            dp[i * j] = std::min(dp[i * j], dp[i] + 4 + (j - 1) * 2);
        }
    }
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k) {
        scanf("%d", &n);
        printf("Case #%d: %d\n", k, dp[n]);
    }
}
