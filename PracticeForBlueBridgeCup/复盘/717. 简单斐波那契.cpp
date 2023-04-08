#include <cstdio>

const int N = 50;

int n;
int f[N];

int main() {
    scanf("%d", &n);
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i < n; ++i) f[i] = f[i - 1] + f[i - 2];
    for (int i = 0; i < n; ++i) printf("%d ", f[i]);
}
