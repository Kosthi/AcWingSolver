// STL Ver
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 20010, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int vis[M];
int node;
queue<int> q;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(int p) {
    memset(vis, 0, sizeof vis);
    q.push(p);
    vis[p] = 1;
    int dist = 0;
    while (q.size()) {
        int s = q.size();
        while (s--) {
            int t = q.front(); q.pop();
            node = t;
            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (!vis[j]) {
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
        dist++;
    }
    return dist - 1;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &m);
    int f;
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &f);
        add(f, i), add(i, f);
    }
    for (int i = n + 1; i <= n + m; ++i) {
        scanf("%d", &f);
        add(f, i), add(i, f);
    }
    bfs(1);
    printf("%d", bfs(node));
}

// simulate Ver
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 20010, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int vis[M];
int node;
int q[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(int p) {
    int hh = 0, tt = 0;
    memset(vis, 0, sizeof vis);
    q[hh] = p;
    vis[p] = 1;
    int dist = 0, s = 1, a = 1;
    while (hh <= tt) {
        s = a;
        a = 0;
        while (s--) {
            int t = q[hh++];
            node = t;
            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (!vis[j]) {
                    a++;
                    q[++tt] = j;
                    vis[j] = 1;
                }
            }
        }
        dist++;
    }
    return dist - 1;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &m);
    int f;
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &f);
        add(f, i), add(i, f);
    }
    for (int i = n + 1; i <= n + m; ++i) {
        scanf("%d", &f);
        add(f, i), add(i, f);
    }
    bfs(1);
    printf("%d", bfs(node));
}

// Dfs Ver
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 20010, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int ans;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
    int d1 = 0, d2 = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        int d = dfs(j);
        if (d > d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;
    }
    ans = max(ans, d1 + d2);
    return d1 + 1;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &m);
    int f;
    for (int i = 2; i <= n + m; ++i) {
        scanf("%d", &f);
        add(f, i);
    }
    dfs(1);
    printf("%d", ans);
}
