#include <iostream>
#include <cstring>

using namespace std;

const int N = 11;

int t, m, n;
int dp[N][N];

int main() {
    cin >> t;
    while (t--) {
        cin >> m >> n;
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 0; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1];
                if (i >= j) dp[i][j] += dp[i - j][j];
            }
        cout << dp[m][n] << endl;;
    }
}
