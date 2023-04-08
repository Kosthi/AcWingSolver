#include <iostream>

using namespace std;

const int N = 110, W = 200010, B = W / 2;

int n, s, ans, w[N];
bool f[N][W];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
        s += w[i];
    }
    f[0][B] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = -s; j <= s; ++j) {
            f[i][B + j] = f[i - 1][B + j];
            if (j + w[i] <= s) f[i][B + j] |= f[i - 1][j + w[i] + B];
            if (j - w[i] >= -s) f[i][B + j] |= f[i - 1][j - w[i] + B];
        }
    }
    for (int i = 1; i <= s; ++i)
        if (f[n][i + B]) ans++;
    printf("%d", ans);
}
