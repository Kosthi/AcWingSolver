#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 2010;
const double INF = 1.7e300;

int n, m, d;
int a[N], b[N];
double dp[N][N][2];

int main() {
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    dp[0][0][0] = 0;
    dp[0][0][1] = d;
    dp[0][1][0] = INF;
    dp[0][1][1] = hypot(d, b[1]);

    for (int i = 1; i <= n; ++i) {
        dp[i][0][0] = a[i];
        dp[i][0][1] = INF;
    }

    for (int i = 1; i <= m; ++i) {
        dp[0][i][0] = INF;
        dp[0][i][1] = d + b[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j][0] = min(dp[i - 1][j][0] + a[i] - a[i - 1], dp[i - 1][j][1] + hypot(d, a[i] - b[j]));
            dp[i][j][1] = min(dp[i][j - 1][1] + b[j] - b[j - 1], dp[i][j - 1][0] + hypot(d, a[i] - b[j]));
        }
    }
    
    printf("%.2lf\n", min(dp[n][m][0], dp[n][m][1]));
}
