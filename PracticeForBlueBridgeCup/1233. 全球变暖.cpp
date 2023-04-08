#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define x first
#define y second

const int N = 1010;

typedef pair<int, int> PII;

char a[N][N];
PII q[N * N];
bool st[N][N];

int n, total, bound, cnt;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void bfs(int i, int j) {
    int hh = 0, tt = 0;
    q[hh] = {i, j};
    st[i][j] = true;
    
    while (hh <= tt) {
        auto t = q[hh++];
        total++;
        bool is_bound = false;
        
        for (int i = 0; i < 4; ++i) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= n) continue;
            if (st[x][y]) continue;
            if (a[x][y] == '.') {
                is_bound = true;
                continue;
            }
            q[++tt] = {x, y};
            st[x][y] = true;
        }
        if (is_bound) bound++;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", a[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!st[i][j] && a[i][j] == '#') {
                total = 0, bound = 0;
                bfs(i, j);
                if (total == bound) cnt++;
            }
    cout << cnt << endl;
}
