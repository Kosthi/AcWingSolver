#include <cstdio>
#include <cstring>

const int N = 100010;

int n, sum;
int a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i && a[i] - a[i - 1] > 0)
            sum += a[i] - a[i - 1];
    }
    printf("%d", sum);
}
