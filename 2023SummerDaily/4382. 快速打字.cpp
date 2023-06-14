#include <cstdio>
#include <cstring>

const int N = 100010;

int T;
char s1[N], s2[N];
int ans;

int main() {
    scanf("%d", &T);
    for (int k = 0; k < T; ++k) {
        scanf("%s", s1);
        scanf("%s", s2);
        int n1 = strlen(s1), n2 = strlen(s2);
        int i = 0, j = 0;
        for (; i < n1 && j < n2; ++j) {
            if (s1[i] == s2[j]) ++i;
        }
        if (i == n1) printf("Case #%d: %d\n", k + 1, n2 - n1);
        else printf("Case #%d: IMPOSSIBLE\n", k + 1);
    }
}
