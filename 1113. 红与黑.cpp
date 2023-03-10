// bfs
#include <iostream>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 25;

int w, h;
char a[N][N];
bool st[N][N];
PII q[N * N];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int bfs(PII start) {
    int hh = 0, tt = 0, cnt = 1;
    st[start.x][start.y] = true; 
    q[hh] = start;
    
    while (hh <= tt) {
        auto t = q[hh++];
        
        for (int i = 0; i < 4; ++i) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x >= h || y < 0 || y >= w) continue;
            if (a[x][y] == '#') continue;
            if (st[x][y]) continue;
            st[x][y] = true;
            q[++tt] = {x, y};
            cnt++;
        }
    }
    return cnt;
}

int main() {
    while (cin >> w >> h, w) {
        PII start;
        memset(st, 0, sizeof st);
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j) {
                cin >> a[i][j];
                if (a[i][j] == '@') start = {i, j};
            }
        cout << bfs(start) << endl;
    }
}

// dfs
#include <iostream>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 25;

int w, h, cnt;
char a[N][N];
bool st[N][N];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void dfs(PII start) {
    st[start.x][start.y] = true;
    cnt++;
    for (int i = 0; i < 4; ++i) {
        int x = start.x + dx[i], y = start.y + dy[i];
        if (x < 0 || x >= h || y < 0 || y >= w) continue;
        if (a[x][y] == '#') continue;
        if (st[x][y]) continue;
        st[x][y] = true;
        dfs({x, y});
    }
}

int main() {
    while (cin >> w >> h, w) {
        cnt = 0;
        PII start;
        memset(st, 0, sizeof st);
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j) {
                cin >> a[i][j];
                if (a[i][j] == '@') start = {i, j};
            }
        dfs(start);
        cout << cnt << endl;
    }
}
