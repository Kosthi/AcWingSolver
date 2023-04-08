#include <cstdio>
#include <cstring>
#include <queue>

#define x first
#define y second

using namespace std;

const int N = 200010;

typedef pair<int, int> PII;

int n, m;
int a, b, c, d;
int v[N];
priority_queue<PII, vector<PII>, greater<PII>> q[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
    while (m--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        while (q[b].size() && q[b].top().x <= a) {
            v[b] += q[b].top().y;
            q[b].pop();
        }
        if (v[b] < d) puts("-1");
        else {
            q[b].push({a + c, d});
            v[b] -= d;
            printf("%d\n", v[b]);
        }
    }
}
