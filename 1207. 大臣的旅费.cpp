// dfs 
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100010;

struct node {
    int s, w;
};

int n, p, q, d;
vector<node> g[N];
int dis[N];

void dfs(int u, int father, int distance) {
    dis[u] = distance;
    
    for (auto node : g[u])
        if (node.s != father)
            dfs(node.s, u, distance + node.w);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d %d", &p, &q, &d);
        g[p].push_back({q, d});
        g[q].push_back({p, d});
    }
    
    dfs(1, -1, 0);
    
    int u = 1;
    for (int i = 1; i <= n; ++i) {
        if (dis[i] > dis[u])
            u = i;
    }
    
    dfs(u, -1, 0);
    
    for (int i = 1; i <= n; ++i) {
        if (dis[i] > dis[u])
            u = i;
    }
    
    printf("%lld", 10 * dis[u] + (1ll + dis[u]) * dis[u] / 2);
}

// bfs
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100010;

struct node {
    int s, w;
};

int n, p, q, d;
vector<node> g[N];
int queue[N];
int dis[N];

void bfs(int u) {
    memset(dis, 0, sizeof dis);
    int hh = 0, tt = 0;
    queue[hh] = u;
    while (hh <= tt) {
        auto t = queue[hh++];
        
        for (auto node : g[t]) {
            if (dis[node.s] || node.s == u) continue;
            dis[node.s] = dis[t] + node.w;
            queue[++tt] = node.s;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d %d", &p, &q, &d);
        g[p].push_back({q, d});
        g[q].push_back({p, d});
    }
    
    bfs(1);
    
    int u = 1;
    for (int i = 1; i <= n; ++i) {
        if (dis[i] > dis[u])
            u = i;
    }
    
    bfs(u);
    for (int i = 1; i <= n; ++i) {
        if (dis[i] > dis[u])
            u = i;
    }
    printf("%lld", 10 * dis[u] + (1ll + dis[u]) * dis[u] / 2);
}
