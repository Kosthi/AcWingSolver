#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 110, M = 10010;

int n, m;
int s[N], h;
int ans;
int f[M];

int sg(int x) {
    if (f[x] != -1) return f[x];
    
    unordered_set<int> S;
    for (int i = 0; i < n; ++i) {
        if (x >= s[i]) S.insert(sg(x - s[i]));
    }
    for (int i = 0; ; ++i) {
        if (!S.count(i)) return f[x] = i;
    }
}

int main() {
    memset(f, -1, sizeof f);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &h);
        ans ^= sg(h);
    }
    if (ans) puts("Yes");
    else puts("No");
}
