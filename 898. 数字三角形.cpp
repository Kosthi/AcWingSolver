#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;

int n;
int f[N][N];


int main() {
    cin >> n;
    memset(f, -0x3f, sizeof f);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> f[i][j];
        }
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + f[i][j];
        }
    }
    int ans = INT32_MIN;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, f[n][i]);
    }
    cout << ans << endl;
}
