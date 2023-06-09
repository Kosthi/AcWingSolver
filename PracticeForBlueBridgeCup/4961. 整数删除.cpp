#include <cstdio>
#include <queue>

#define x first
#define y second

using namespace std;

const int N = 500010;

typedef long long LL;
typedef pair<LL, int> PII;

int n, k, p;
LL e[N];
int l[N], r[N], idx;
LL sum[N];
priority_queue<PII, vector<PII>, greater<PII> > q;

void init() {
    r[0] = 1, l[1] = 0;
    idx = 2;
}

void add(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void remove(int k) {
    r[l[k]] = r[k], l[r[k]] = l[k];
}

void op(int k) {
    if (l[k] != 1) {
        e[l[k]] += e[k];
        sum[l[k] - 2] += e[k];
    }
    if (r[k] != 0) {
        e[r[k]] += e[k];
        sum[r[k] - 2] += e[k];
    }
    remove(k);
}

int main() {
    init();
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p);
        add(l[1], p);
        q.push({p, i});
    }
    while (k--) {
        PII t = q.top();
        q.pop();
        while (sum[t.y]) {
            q.push({t.x + sum[t.y], t.y});
            sum[t.y] = 0;
            t = q.top();
            q.pop();
        }
        op(t.y + 2);
    }
    for (int i = r[0]; i != 1; i = r[i]) printf("%lld ", e[i]);
}
