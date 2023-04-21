#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 0x3f3f3f3f

using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N], st[N];
int a, b, c;

int Dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        
        st[t] = 1;
        
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    
    if (dist[n] == INF) return -1;
    return dist[n];
}

int main() {
    scanf("%d %d", &n, &m);
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    printf("%d", Dijkstra());
}
