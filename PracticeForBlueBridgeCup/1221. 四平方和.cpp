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

// 二分
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 5 * 1e6;

int n;

struct Sum {
    int s, c, d;
    bool operator<(const Sum &p) const {
        if (s != p.s) return s < p.s;
        if (c != p.c) return c < p.c;
        return d < p.d;
    }
}sum[N];

int i;

int main() {
    cin >> n;
    for (int c = 0; c * c * 2 <= n; ++c) {
        for (int d = c; d * d <= n - c * c; ++d) {
            sum[i++] = {c * c + d * d, c, d};
        }
    }
    
    sort(sum, sum + i);
    
    for (int a = 0; a * a * 4 <= n; ++a) {
        for (int b = a; b * b * 3 <= n - a * a; ++b) {
            int p = n - a * a - b * b;
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (sum[mid].s >= p) r = mid;
                else l = mid + 1;
            }
            if (sum[r].s == p) {
                printf("%d %d %d %d\n", a, b, sum[r].c, sum[r].d);
                return 0;
            }
        }
    }
}

// 哈希
#pragma GCC optimize(2) // 不能在竞赛中使用
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define x first
#define y second

using namespace std;

const int N = 5 * 1e6;

int n;

typedef pair<int, int> PII;
unordered_map<int, PII> S;

int i;

int main() {
    scanf("%d", &n);
    for (int c = 0; c * c * 2 <= n; ++c) {
        for (int d = c; d * d <= n - c * c; ++d) {
            int t = c * c + d * d;
            if (S.count(t) == 0) S[t] = {c, d};
        }
    }
    
    for (int a = 0; a * a * 4 <= n; ++a) {
        for (int b = a; b * b * 3 <= n - a * a; ++b) {
            int p = n - a * a - b * b;
            if (S.count(p)) {
                printf("%d %d %d %d\n", a, b, S[p].x, S[p].y);
                return 0;
            }
        }
    }
}

// 模拟哈希 400ms
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define x first
#define y second

using namespace std;

const int N = 5 * 1e6;

int n;

typedef pair<int, int> PII;
PII C[N];

int main() {
    scanf("%d", &n);
    memset(C, -1, sizeof C);
    for (int c = 0; c * c * 2 <= n; ++c) {
        for (int d = c; d * d <= n - c * c; ++d) {
            int t = c * c + d * d;
            if (C[t].x == -1) C[t] = {c, d};
        }
    }
    
    for (int a = 0; a * a * 4 <= n; ++a) {
        for (int b = a; b * b * 3 <= n - a * a; ++b) {
            int p = n - a * a - b * b;
            if (C[p]. x != -1 ) {
                printf("%d %d %d %d\n", a, b, C[p].x, C[p].y);
                return 0;
            }
        }
    }
}

// 模拟哈希 双数组 350ms
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5 * 1e6;

int n;
int C[N], D[N];


int main() {
    scanf("%d", &n);
    memset(C, -1, sizeof C);
    for (int c = 0; c * c * 2 <= n; ++c) {
        for (int d = c; d * d <= n - c * c; ++d) {
            int t = c * c + d * d;
            if (C[t] == -1) {
                C[t] = c;
                D[t] = d;
            }
        }
    }
    
    for (int a = 0; a * a * 4 <= n; ++a) {
        for (int b = a; b * b * 3 <= n - a * a; ++b) {
            int p = n - a * a - b * b;
            if (C[p] != -1) {
                printf("%d %d %d %d\n", a, b, C[p], D[p]);
                return 0;
            }
        }
    }
}
