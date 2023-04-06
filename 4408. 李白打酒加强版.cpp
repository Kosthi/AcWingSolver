#include <cstdio>
#include <cstring>

const int N = 110, M = 1000000007;

int dp[N][N][N];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    dp[0][0][2] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= m; ++k) {
                if (k % 2 == 0 && i >= 1) dp[i][j][k] = dp[i - 1][j][k / 2];
                if (j >= 1) dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k + 1]) % M;
            }
        }
    }
    printf("%d", dp[n][m - 1][1]);
}
