#include <cstdio>
#include <iostream>

using namespace std;

const int N = 200000;

typedef long long LL;

int n;
LL m;
int a[N], b[N];

bool check(LL p) {
    LL t = m;
    for (int i = 0; i < n; ++i) {
        if (a[i] + b[i] < p) return false;
        else if (a[i] < p && t >= p - a[i]) t -= p - a[i];
        else if (t < p - a[i]) return false;
    }
    return true;
}

int main() {
    scanf("%d %lld", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    LL l = 1, r = m;
    while (l < r) {
        LL mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << endl;
}
