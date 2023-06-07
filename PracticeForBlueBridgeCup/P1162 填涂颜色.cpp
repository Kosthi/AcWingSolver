#include <cstdio>

using namespace std;

const int N = 50;

int n;
int map[N][N];
bool st[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0,1};

void dfs_1(int r, int c) {
    st[r][c] = true;
    for (int i = 0; i < 4; ++i) {
        int x = r + dx[i], y = c + dy[i];
        if (x < 0 || x > n + 1 || y < 0 || y > n + 1) continue;
        if (st[x][y]) continue;
        if (map[x][y] == 1) dfs_1(x, y);
    }
}

void dfs_0(int r, int c) {
    st[r][c] = true;
    for (int i = 0; i < 4; ++i) {
        int x = r + dx[i], y = c + dy[i];
        if (x < 0 || x > n + 1 || y < 0 || y > n + 1) continue;
        if (st[x][y]) continue;
        if (map[x][y] == 1) dfs_1(x, y);
        else dfs_0(x, y);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &map[i][j]);
    dfs_0(0, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!st[i][j]) printf("2 ");
            else printf("%d ", map[i][j]);
        }
        puts("");
    }
}
