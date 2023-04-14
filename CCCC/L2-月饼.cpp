#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
double d;
double v[N], w[N];
double ans;

struct S {
    double j;
    int k;
    bool operator<(const S& s) const {
        return j > s.j;
    }
}s[N];

int main() {
    cin >> n >> d;
    for (int i = 0;i < n; ++i) cin >> v[i];
    for (int i = 0;i < n; ++i) cin >> w[i];
    for (int i = 0; i < n; ++i) {
        s[i].j = w[i] / v[i];
        s[i].k = i;
    }
    sort(s, s + n);
    for (int i = 0; i < n; ++i) {
        if (v[s[i].k] <= d) {
            d -= v[s[i].k];
            ans += w[s[i].k];
        }
        else {
            ans += d * s[i].j;
            break;
        }
    }
    printf("%.2lf", ans);
}
