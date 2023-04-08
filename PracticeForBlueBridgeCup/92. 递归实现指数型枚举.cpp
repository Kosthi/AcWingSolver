#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define MOD 1000000007

using namespace std;

const int N = 60;

int n, m, k, c;
int a[N][N];
LL f[N][N][13][14];


int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            a[i][j]++;
        }
    }
    int res = k;
    f[1][1][1][a[1][1]] = 1;
    f[1][1][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k <= 12; ++k) {
                for (int c = 0; c <= 13; ++c) {
                    f[i][j][k][c] += f[i - 1][j][k][c] % MOD;
                    f[i][j][k][c] += f[i][j - 1][k][c] % MOD;
                    if (k > 0 && a[i][j] == c) {
                        for (int u = 0; u < c; ++u) {
                            f[i][j][k][c] += f[i - 1][j][k - 1][u] % MOD;
                            f[i][j][k][c] += f[i][j - 1][k - 1][u] % MOD;
                        }
                    }
                }
            }
        }
    }

    LL ans = 0;
    for (int i = 0; i <= 13; ++i) {
        ans += f[n][m][res][i];
        ans %= 1000000007;
    }
    cout << ans << endl;
}
