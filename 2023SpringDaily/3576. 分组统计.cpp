#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

const int N = 110;

int a[N][1010], b[N];

int T, n, k;
set<int> s, p;

int main() {
    scanf("%d", &T);
    while (T--) {
        s.clear(), p.clear();
        memset(a, 0, sizeof a);

        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
            s.insert(b[i]);
        }

        for (int i = 0; i < n; ++i) {
            scanf("%d", &k);
            a[k][b[i]]++;
            p.insert(k);
        }

        for (int i = 1; i <= p.size(); ++i) {
            printf("%d={", i);
            for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
                if (it == --s.end()) printf("%d=%d}\n", *it, a[i][*it]);
                else printf("%d=%d,", *it, a[i][*it]);
            }
        }
    }
}
