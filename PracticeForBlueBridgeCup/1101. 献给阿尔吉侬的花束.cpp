#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define x first
#define y second

using namespace std;

const int N = 210;

typedef pair<int, int> PII;

int T, r, c;
char a[N][N];
int dist[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int bfs(PII start, PII end) {
    queue<PII> q;
    dist[start.x][start.y] = 0;
    q.push(start);
    
    while (q.size()) {
        auto t = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x >= r || y < 0 || y >= c) continue;
            if (a[x][y] == '#') continue;
            if (dist[x][y]) continue;
            
            dist[x][y] = dist[t.x][t.y] + 1;
            PII tmp = {x, y};
            if (tmp == end) return dist[x][y];
            q.push(tmp);
        }
    }
    return -1;
}

int main() {
    cin >> T;
    while (T--) {
        memset(dist, 0, sizeof dist);
        PII start, end;
        cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> a[i][j];
                if (a[i][j] == 'S') start = {i, j};
                if (a[i][j] == 'E') end = {i, j};
            }
        }
        int ans = bfs(start, end);
        if (ans == -1) {
            cout << "oop!" << endl;
        }
        else {
            cout << ans << endl;
        }
        
    }
}
