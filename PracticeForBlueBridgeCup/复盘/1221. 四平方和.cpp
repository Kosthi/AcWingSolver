#include <cstdio>
#include <cmath>

int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i * i <= n / 4; ++i) {
        for (int j = i; j * j <= (n - i * i) / 3; ++j) {
            for (int k = j; k * k <= (n - i * i - j * j) / 2; ++k) {
                int p = sqrt(n - i * i - j * j - k * k);
                if (p * p + i * i + j * j + k * k == n) {
                    printf("%d %d %d %d\n", i, j, k, p);
                    return 0;
                }
            }
        }
    }
}

#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

const int N = 5000010;

int n;

struct Sum {
    int s, c, d;
    bool operator<(const Sum& s2) const {
        if (s != s2.s) return s < s2.s;
        if (c != s2.c) return c < s2.c;
        return d < s2.d;
    }
}s[N];

int main() {
    scanf("%d", &n);
    int k = 0;
    for (int i = 0; i * i <= n; ++i) {
        for (int j = i; j * j <= n - i * i; ++j) {
            s[k++] = {i * i + j * j, i, j};
        }
    }
    std::sort(s, s + k);
    for (int i = 0; i * i <= n; ++i) {
        for (int j = i; j * j <= n - i * i; ++j) {
            int p = n - i * i - j * j;
            int l = 0, r = k - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (s[mid].s >= p) r = mid;
                else l = mid + 1;
            }
            if (s[r].s == p) {
                printf("%d %d %d %d\n", i, j, s[r].c, s[r].d);
                return 0;
            }
        }
    }
}

#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 5000010;

int n;
int s[N], cnt[N];

int main() {
    scanf("%d", &n);
    int k = 0;
    memset(s, -1, sizeof s);
    for (int i = 0; i * i <= n; ++i) {
        for (int j = i; j * j <= n - i * i; ++j) {
            // 25 = 0, 5或者3，4，需要判重
            if (s[i * i + j * j] == -1) s[i * i + j * j] = i;
        }
    }
    for (int i = 0; i * i <= n; ++i) {
        for (int j = i; j * j <= n - i * i; ++j) {
            int p = n - i * i - j * j;
            if (s[p] == -1) continue;
            else {
                // sqrt返回值为浮点数，%d会溢出
                printf("%d %d %d %.0f\n", i, j, s[p], sqrt(p - s[p] * s[p]));
                return 0;
            }
        }
    }
}

