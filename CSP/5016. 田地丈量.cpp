#include <cstdio>

const int N = 10010, M = 110;

int n, a, b;
int st[N][N];

int x1, y1, x2, y2;

int ans;

int main() {
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int j = x1; j < x2; j++)
            for (int k = y1; k < y2; ++k)
                if (j >= 0 && j < a && k >= 0 && k < b) ans++;
    }
    printf("%d", ans);
}
