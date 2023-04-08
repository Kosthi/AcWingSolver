// dp
#include <iostream>

using namespace std;

const int N = 40;

int f[N][N];
int n, m;

int main() {
    cin >> n >> m;
    f[1][1] = 1;
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= m; ++y) {
            if (x == 1 && y == 1) continue;
            if (x & 1 || y & 1) f[x][y] = f[x - 1][y] + f[x][y - 1];
        }
    cout << f[n][m];
}

// dfs 记忆化
#include <iostream>

using namespace std;

const int N = 40;

int f[N][N];
int n, m;

int dfs(int x, int y) {
    if (f[x][y]) return f[x][y];
    if (x % 2 == 0 && y % 2 == 0) return 0;
    if (x > n || y > m) return 0;
    if (x == n && y == m) return f[x][y];
    f[x][y] += dfs(x, y + 1);
    f[x][y] += dfs(x + 1, y);
    return f[x][y];
}

int main() {
    cin >> n >> m;
    f[n][m] = n & 1 || m & 1;
    cout << dfs(1, 1);
}
