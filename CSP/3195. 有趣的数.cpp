#include <iostream>

using namespace std;

const int N = 1010, M = 1e9 + 7;

typedef long long LL;

int n;
int c[N][N];
LL ans;

int main() {
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
        }
    }
    for (int k = 2; k <= n - 2; ++k) {
        ans = (ans + (LL)c[n - 1][k] * (k - 1) * (n - k - 1)) % M;
    }
    cout << ans << endl;
}
