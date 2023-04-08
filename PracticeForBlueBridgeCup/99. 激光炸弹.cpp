// ver0 optimize 1600ms
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;
int cnt, r, maxw, ans, m, n;
int s[N][N];


int main() {
    scanf("%d %d", &cnt, &r);
    r = min(r, 5001);
    m = n = r;
    while (cnt--) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        s[x + 1][y + 1] += w;
        m = max(m, x + 1), n = max(n, y + 1);
    }
    
    for (int x = 1; x <= m; ++x) {
        for (int y = 1; y <= n; ++y) {
            s[x][y] += s[x][y - 1] + s[x - 1][y] - s[x - 1][y - 1];
        }
    }
    
    for (int x = r; x <= m; ++x) {
        for (int y = r; y <= n; ++y) {
            ans = s[x][y] - s[x - r][y] - s[x][y - r] + s[x - r][y - r];
            maxw = max(maxw, ans);
        }
    }
    printf("%d\n", maxw);
}

// ver1 4000ms
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;
int n, r, maxw, ans;
int s[N][N];


int main() {
    scanf("%d %d", &n, &r);
    r = min(r, 5001);
    while (n--) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        s[x + 1][y + 1] += w;
    }
    
    for (int x = 1; x <= 5001; ++x) {
        for (int y = 1; y <= 5001; ++y) {
            s[x][y] = s[x][y - 1] + s[x - 1][y] - s[x - 1][y - 1] + s[x][y];
        }
    }
    // 5002 - r，防止右下角下标越界
    for (int x1 = 1; x1 <= 5002 - r; ++x1) {
        for (int y1 = 1; y1 <= 5002 - r; ++y1) {
            int x2 = x1 + r - 1, y2 = y1 + r - 1;
            ans = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
            maxw = max(maxw, ans);
        }
    }
    printf("%d\n", maxw);
}

// ver2 3500ms
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;
int n, r, maxw, ans;
int s[N][N];


int main() {
    scanf("%d %d", &n, &r);
    r = min(r, 5001);
    while (n--) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        s[x + 1][y + 1] += w;
    }
    
    for (int x = 1; x <= 5001; ++x) {
        for (int y = 1; y <= 5001; ++y) {
            s[x][y] = s[x][y - 1] + s[x - 1][y] - s[x - 1][y - 1] + s[x][y];
        }
    }
    // 5001 防止下标为负，输出0
    for (int x = r; x <= 5001; ++x) {
        for (int y = r; y <= 5001; ++y) {
            ans = s[x][y] - s[x - r][y] - s[x][y - r] + s[x - r][y - r];
            maxw = max(maxw, ans);
        }
    }
    printf("%d\n", maxw);
}
