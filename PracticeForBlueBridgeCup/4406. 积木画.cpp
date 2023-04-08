#include <cstdio>

const int N = 10000010, M = 1000000007;

int n;
int dp[N][4];

int g[4][4] = {
    {1, 1, 1, 1},
    {0, 0, 1, 1},
    {0, 1, 0, 1},
    {1, 0, 0, 0},
};

int main() {
    scanf("%d", &n);
    dp[1][0] = 1;
    for (int i = 1; i <= n; ++i) {
        // 上个状态 dp[i][j]
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                // 当前状态 dp[i + 1][k]
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j] * g[j][k]) % M;
            }
        }
    }
    printf("%d", dp[n + 1][0]);
}

#include <cstdio>
#include <cstring>

const int N = 10000010, M = 1000000007;

int n;
int dp[2][4];

int g[4][4] = {
    {1, 1, 1, 1},
    {0, 0, 1, 1},
    {0, 1, 0, 1},
    {1, 0, 0, 0},
};

// 滚动数组不一定需要降维，目的只是空间优化
int main() {
    scanf("%d", &n);
    dp[1][0] = 1;
    for (int i = 1; i <= n; ++i) {
        // 上个状态 dp[i][j]
        memset(dp[i + 1 & 1], 0, sizeof dp[0]);
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                // 当前状态 dp[i + 1][k]
                dp[i + 1 & 1][k] = (dp[i + 1 & 1][k] + dp[i & 1][j] * g[j][k]) % M;
            }
        }
    }
    printf("%d", dp[n + 1 & 1][0]);
}
