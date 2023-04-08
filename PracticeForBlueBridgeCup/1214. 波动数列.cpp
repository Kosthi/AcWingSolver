#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MOD 100000007

using namespace std;

const int N = 1010;

int f[N][N];
int n, s, a, b;

int get_mod(int a, int b) {
    return (a % b + b) % b;
}

int main() {
    cin >> n >> s >> a >> b;
    f[0][0] = 1;
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            f[i][j] = (f[i][j] + f[i - 1][get_mod(j - i * a, n)]) % MOD;
            f[i][j] = (f[i][j] + f[i - 1][get_mod(j + i * b, n)]) % MOD;
        }
    }
    cout << f[n - 1][get_mod(s, n)] << endl;
}
