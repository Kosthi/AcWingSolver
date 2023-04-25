#include <cstdio>

const int N = 15;

int n, m;

struct windows {
    int x1, y1, x2, y2, id;
}w[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d %d %d %d", &w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2), w[i].id = i;
    int x, y;
    while (m--) {
        scanf("%d %d", &x, &y);
        int i;
        for (i = n; i >= 1; --i) {
            if (w[i].x1 <= x && x <= w[i].x2 && w[i].y1 <= y && y <= w[i].y2) {
                windows tmp = w[i];
                printf("%d\n", w[i].id);
                for (int j = i; j < n; ++j) w[j] = w[j + 1];
                w[n] = tmp;
                break;
            }
        }
        if (i == 0) puts("IGNORED");
    }
}
