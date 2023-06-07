#include <cstdio>
#include <cstring>

const int N = 60;

int T, n, m;
char map[N][N];
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
bool st[N][N];
int ans;

void dfs_1(int x, int y) {
    st[x][y] = true;
    
    for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx > n + 1 || yy < 0 || yy > m + 1) continue;
        if (st[xx][yy]) continue;
        if (map[xx][yy] == '1') dfs_1(xx, yy);
    }
}

void dfs_0(int x, int y) {
    st[x][y] = true;
    
    for (int i = 0; i < 8; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx > n + 1 || yy < 0 || yy > m + 1) continue;
        if (st[xx][yy]) continue;
        if (map[xx][yy] == '1') dfs_1(xx, yy), ans++;
        else dfs_0(xx, yy);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        memset(st, 0, sizeof st);
        memset(map, '0', sizeof map);
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%s", map[i] + 1);
        dfs_0(0, 0);
        printf("%d\n", ans);
    }
}
