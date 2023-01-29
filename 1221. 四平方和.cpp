#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 5 * 1e6;

// 优化暴搜
int main() {
    cin >> n;
    for (int i = 0; i * i * 4 <= n; ++i) {
        for (int j = i; j * j * 3 <= n - i * i; ++j) {
            for (int k = j; k * k * 2 <= n - j * j - i * i; ++k) {
                int p = n - i * i - j * j - k * k;
                int u = sqrt(p);
                if (u * u == p) {
                    printf("%d %d %d %d\n", i, j, k, u);
                    return 0;
                }
            }
        }
    }
}

