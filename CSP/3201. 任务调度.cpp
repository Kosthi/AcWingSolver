#include <iostream>
#include <cstring>

const int N = 300, INF = 0x3f3f3f3f;

using namespace std;

int n;
int c[N][3];
int dp[2][N][N][N];
int a, b, cc, d;
int m;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d %d", &a, &b, &cc, &d);
        c[i][0] = a, c[i][1] = cc, c[i][2] = min(b, d);
        m += a;
    }
    m = (m + 1) / 2;
    memset(dp, INF, sizeof dp);
    dp[0][0][0][0] = 0;
    for (int u = 1; u <= n; ++u)
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= m; ++k) {
                    int& v = dp[u & 1][i][j][k];
                    register int x = c[u][0], y = c[u][1], z = c[u][2], t = u - 1 & 1;
                    v = dp[t][i][j][k] + z;
                    if (i >= x) v = min(v, dp[t][i - x][j][k]);
                    if (j >= x) v = min(v, dp[t][i][j - x][k]);
                    if (i >= y && k >= y) v = min(v, dp[t][i - y][j][k - y]);
                    if (j >= y && k >= y) v = min(v, dp[t][i][j - y][k - y]);
                }
            }
        }
    
    int ans = INF;
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j)
            for (int k = 0; k <= m; ++k)
                ans = min(ans, dp[n & 1][i][j][k] + max(i, max(j, k)));
                
    printf("%d", ans);
}
