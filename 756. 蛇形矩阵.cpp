#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int q[N][N];
int n, m, x, y;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;
    int d = 1;
    for (int i = 1; i <= n * m; ++i) {
        q[x][y] = i;
        int a = x + dx[d], b = y + dy[d];
        
        if (a < 0 || a >= n || b < 0 || b >= m || q[a][b]) {
            d = (d + 1) % 4;
            a = x + dx[d], b = y +  dy[d];
        }
        x = a, y = b;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << q[i][j] << " ";
        cout << endl;
    }
}
