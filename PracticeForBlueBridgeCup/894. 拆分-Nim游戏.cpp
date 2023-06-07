#include <cstdio>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 110;

int n, k;
int ans;
int f[N];

int sg(int x) {
    if (f[x] != -1) return f[x];
    
    unordered_set<int> S;
    
    for (int i = x - 1; ~i; --i) {
        for (int j = i; ~j; --j) {
            S.insert(sg(i) ^ sg(j));
        }
    }
    
    for (int i = 0; ; ++i)
        if (!S.count(i)) return f[x] = i;
}

int main() {
    memset(f, -1, sizeof f);
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        ans ^= sg(k);
    }
    if (ans) puts("Yes");
    else puts("No");
}
