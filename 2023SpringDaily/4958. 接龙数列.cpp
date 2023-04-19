#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int l, r;
int f, g[20], res;
char s[20];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        l = s[0] - '0', r= s[strlen(s) - 1] - '0';
        f = max(1, g[l] + 1);
        g[r] = max(f, g[r]);
        res = max(res, f);
    }
    printf("%d", n - res);
}
