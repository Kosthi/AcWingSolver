#include <iostream>

const int N = 2010, M = 10010;

using namespace std;

int n, m, k;
int w[N], v[N];
int dp[N][M][2];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][1] = dp[i - 1][j][1];
            if (j >= w[i]) {
                // no magic
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - w[i]][0] + v[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - w[i]][1] + v[i]);
                // have magic
                if (j >= w[i] + k) dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - w[i] - k][0] + 2 * v[i]);
            }
        }
    }
    cout << max(dp[n][m][0], dp[n][m][1]);
}
