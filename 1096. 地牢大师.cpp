#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

const int N = 110;

typedef pair<int, int> PII;

char a[15000][N];
int dis[15000][N];
int L, R, C;

int bfs(PII start, PII end) {
    queue<PII> q;
    dis[start.x][start.y] = 0;
    q.push(start);
    
    int dx[] = {-1, 0, 1, 0, R, -R}, dy[] = {0, 1, 0, -1, 0, 0};
    while (q.size()) {
        auto t = q.front();
        q.pop();
        
        for (int i = 0; i < 6; ++i) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x >= L * R || y < 0 || y >= C) continue;
            if (dis[x][y]) continue;
            if (a[x][y] == '#') continue;
            
            PII tmp = {x, y};
            dis[x][y] = dis[t.x][t.y] + 1;
            if (tmp == end) return dis[x][y];
            q.push(tmp);
        }
    }
    return -1;
}

int main() {
    while (cin >> L >> R >> C && L) {
        PII start, end;
        memset(dis, 0, sizeof dis);
        for (int i = 0; i < R * L; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> a[i][j];
                if (a[i][j] == 'S') start = {i, j};
                if (a[i][j] == 'E') end = {i, j};
            }
        }
        
        //cout << end.x <<" " <<  end.y;
        int ans = bfs(start, end);
        if (ans == -1) cout << "Trapped!" << endl;
        else cout << "Escaped in " << ans << " minute(s)." << endl;
    }
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

struct node {
    int x, y, z;
    bool operator==(const node& p) const {
        return x == p.x && y == p.y && z == p.z;
    }
};

char a[N][N][N];
int dis[N][N][N];
node q[N * N * N];
int L, R, C;

int dx[] = {-1, 0, 1, 0, 0, 0}, dy[] = {0, 1, 0, -1, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1};

int bfs(node start, node end) {
    int hh = 0, tt = 0;
    q[hh] = start;
    dis[start.x][start.y][start.z] = 0;
    
    while (hh <= tt) {
        node t = q[hh++];
        
        for (int i = 0; i < 6; ++i) {
            int x = t.x + dx[i], y = t.y + dy[i], z = t.z + dz[i];
            if (x < 0 || x >= R || y < 0 || y >= C || z < 0 || z >= L) continue;
            if (dis[x][y][z]) continue;
            if (a[x][y][z] == '#') continue;
            
            node tmp = {x, y, z};
            dis[x][y][z] = dis[t.x][t.y][t.z] + 1;
            if (tmp == end) return dis[x][y][z];
            q[++tt] = tmp;
        }
    }
    return -1;
}

int main() {
    while (cin >> L >> R >> C, L || R || C) {
        node start, end;
        memset(dis, 0, sizeof dis);
        for (int z = 0; z < L; ++z) {
            for (int i = 0; i < R; ++i)
                for (int j = 0; j < C; ++j) {
                    cin >> a[i][j][z];
                    if (a[i][j][z] == 'S') start = {i, j, z};
                    if (a[i][j][z] == 'E') end = {i, j, z};
                }
        }
        
        int ans = bfs(start, end);
        if (ans == -1) cout << "Trapped!" << endl;
        else cout << "Escaped in " << ans << " minute(s)." << endl;
    }
}

