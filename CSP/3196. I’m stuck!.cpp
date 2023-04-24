#include <iostream>

#define x first
#define y second

using namespace std;

const int N = 100;

typedef pair<int, int> PII;

char map[N][N];
int r, c;
PII s, e;
int st[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
PII q[N * N];
int cnt;

void dfs(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
        if (map[x][y] == '-' && i != 1 && i != 3) continue;
        if (map[x][y] == '|' && i != 0 && i != 2) continue;
        if (map[x][y] == '.' && i != 2) continue;
        if (map[xx][yy] == '#') continue;
        if (!st[xx][yy]) {
            st[xx][yy] = 1;
            dfs(xx, yy);
        }
    }
}

bool bfs(PII s) {
    int st[N][N] = {0};
    int hh = 0, tt = 0;
    q[hh] = s;
    while (hh <= tt) {
        PII t = q[hh++];
        int x = t.x, y = t.y;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
            if (map[x][y] == '-' && i != 1 && i != 3) continue;
            if (map[x][y] == '|' && i != 0 && i != 2) continue;
            if (map[x][y] == '.' && i != 2) continue;
            if (map[xx][yy] == '#') continue;
            if (xx == e.x && yy == e.y) return true;
            if (!st[xx][yy]) {
                st[xx][yy] = 1;
                q[++tt] = make_pair(xx, yy);
            }
        }
    }
    return false;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'S') s.x = i, s.y = j;
            if (map[i][j] == 'T') e.x = i, e.y = j;
        }
    dfs(s.x, s.y);
    if (!st[e.x][e.y]) {
        puts("I'm stuck!");
        return 0;
    }
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (st[i][j] && !bfs({i, j})) cnt++;
    cout << cnt << endl;
}
