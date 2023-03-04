#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 10;

int n, m, k, ans;
int a[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
unordered_set<int> set;

void dfs(int i, int j, int s, int num) {
    if (s > k) {
        set.insert(num);
        return;
    }
    for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 1 && x <= n && y >= 1 && y <= m)
            dfs(x, y, s + 1, num * 10 + a[x][y]);
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
            
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dfs(i, j, 1, a[i][j]);
            
    cout << set.size() << endl;
}
