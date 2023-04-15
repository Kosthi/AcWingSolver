#include <iostream>
#include <vector>

using namespace std;

const int N = 110;

int p[N];
int n, m, k;
int x, y, r;
int e[N][N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) p[i] = i;
    while (m--) {
        cin >> x >> y >> r;
        if (r == 1) {
            p[find(x)] = find(y);
        }
        else {
            e[x][y] = -1;
            e[y][x] = -1;
        }
    }
    while (k--) {
        cin >> x >> y;
        if (find(x) == find(y) && e[x][y] != -1)
            cout << "No problem" << endl;
        else if (find(x) != find(y) && e[x][y] != -1)
            cout << "OK" << endl;
        else if (find(x) == find(y) && e[x][y] == -1)
            cout << "OK but..." << endl;
        else if (find(x) != find(y) && e[x][y] == -1)
            cout << "No way" << endl;
    }
}
