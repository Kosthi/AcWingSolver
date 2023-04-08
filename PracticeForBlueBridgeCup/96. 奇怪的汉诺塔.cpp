#include <cstring>
#include <iostream>

using namespace std;

const int N = 15;

int d[N], f[N];

int main() {
    d[1] = 1;
    for (int i = 2; i <= 12; ++i) {
        d[i] = 2 * d[i - 1] + 1;
    }
    memset(f, 0x3f, sizeof f);
    f[1] = 1;
    for (int i = 2; i <= 12; ++i)
        for (int j = 1; j < i; ++j)
            f[i] = min(f[i], 2 * f[j] + d[i - j]);
            
    for (int i = 1; i <= 12; ++i) cout << f[i] << endl;
}
