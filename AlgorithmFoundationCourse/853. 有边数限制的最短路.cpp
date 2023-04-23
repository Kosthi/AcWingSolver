#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, M = 10010, INF = 0x3f3f3f3f;

int n, m, k;
int x, y, z;
int dis[N], backup[N];

struct e {
    int x, y, w;
}edg[M];

int bellman_ford() {
    memset(dis, INF, sizeof dis);
    dis[1] = 0;
    for(int i = 0; i < k; ++i) {
        memcpy(backup, dis, sizeof dis);
        for (int j = 0; j < m; ++j) {
            int x = edg[j].x, y = edg[j].y, w = edg[j].w;
            dis[y] = min(dis[y], backup[x] + w);
        }
    }
    if (dis[n] > INF / 2) return INF;
    return dis[n];
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &z);
        edg[i] = {x, y, z};
    }
    int t = bellman_ford();
    if (t == INF) printf("impossible");
    else printf("%d", t);
}
