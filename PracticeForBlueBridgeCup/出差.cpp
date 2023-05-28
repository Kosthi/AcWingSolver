#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, INF = 0x3f3f3f3f;

int n, m;
int v[N];
int dist[N], g[N][N];
int st[N];
int a, b, vv;

int dijkstra() {
    memset(dist, INF, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        st[t] = 1;
        for (int j = 1; j <= n; ++j)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    return dist[n] - v[n - 1];
}

int main() {
    memset(g, INF, sizeof g);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &vv);
        g[a][b] = vv + v[b - 1];
        g[b][a] = vv + v[a - 1];
    }
    cout << dijkstra() << endl;
}
