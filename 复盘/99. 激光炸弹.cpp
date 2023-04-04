#include <cstdio>
#include <iostream>

const int N = 5010;

int s[N][N];
int n, r;

int main() {
    scanf("%d %d", &n, &r);
    int x, y, w;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &x, &y, &w);
        s[x + 1][y + 1] += w;
    }
    
    for (int i = 1; i <= 5001; ++i) {
        for (int j = 1; j <= 5001; ++j) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    
    r = std::min(5001, r);
    int maxx = 0;
    for (int i = r; i <= 5001; ++i) {
        for (int j = r; j <= 5001; ++j) {
            // int x1 = i, y1 = j, x2 = r + i - 1, y2 = r + j - 1;
            // maxx = std::max(maxx, s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
            maxx = std::max(maxx, s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r]);
        }
    }
    printf("%d", maxx);
}
