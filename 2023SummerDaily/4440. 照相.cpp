#include <cstdio>

const int N = 200010;

int n, cnt;
char s[N];
int w[N];
int ans;

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n - 1; i += 2) if (s[i] != s[i + 1]) w[cnt++] = s[i] == 'G';
    for (int i = 0; i < cnt; ++i) if (w[i] != w[i + 1]) ans++;
    printf("%d", ans);
}
