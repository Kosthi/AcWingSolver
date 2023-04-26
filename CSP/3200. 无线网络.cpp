#include <iostream>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 300;

int n, m, k, r;
int dist[N][N];
PII p[N], q[N * N];
int h[N], e[N * N], ne[N * N], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs() {
    int hh = 0, tt = 0;
    memset(dist, 0x3f, sizeof dist);
    q[hh] = {1, 0};
    dist[1][0] = 0;
    while (hh <= tt) {
        PII t = q[hh++];
        for (int i = h[t.x]; ~i; i = ne[i]) {
            int x = e[i], y = t.y;
            if (x > n) y++;
            if (y <= k) {
                if (dist[x][y] > dist[t.x][t.y] + 1) {
                    dist[x][y] = dist[t.x][t.y] + 1;
                    q[++tt] = {x, y};
                }
            }
        }
    }
    int ans = 1e8;
    for (int i = 0; i <= k; ++i) ans = min(ans, dist[2][i]);
    return ans - 1;
}

int main() {
    cin >> n >> m >> k >> r;
    for (int i = 1; i <= n + m; ++i) cin >> p[i].x >> p[i].y;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n + m; ++i) {
        for (int j = i + 1; j <= n + m; ++j) {
            if (((LL)p[i].x - p[j].x) * (p[i].x - p[j].x) + ((LL)p[i].y - p[j].y) * (p[i].y - p[j].y) <= (LL)r * r) {
                add(i, j), add(j, i);
            }
        }
    }
    cout << bfs() << endl;
}
