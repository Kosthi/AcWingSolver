#include <cstdio>
#include <cstring>

const int N = 510;

typedef long long LL;

int n, m, k;
int s[N][N];
LL cnt;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &s[i][j]);
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; ++j) {
            for (int l = 1, r = 1; r <= n; ++r) {
                while (l <= r && s[r][j] - s[l - 1][j] - s[r][i - 1] + s[l - 1][i - 1] > k) l++;
                if (l <= r) cnt += r - l + 1;
            }
        }
    }
    printf("%lld", cnt);
}
