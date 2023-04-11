#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;

int a[20];
double s[N];
int n, k, m;

int main() {
    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) cin >> a[j];
        sort(a, a + k);
        for (int p = 1; p < k - 1; ++p) s[i] += a[p];
        s[i] /= k - 2.0;
    }
    sort(s, s + n);
    for (int i = n - m; i < n - 1; ++i) printf("%.3f ", s[i]);
    printf("%.3f", s[n - 1]);
}
