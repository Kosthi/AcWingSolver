#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 500010;

int n;
long double S, cur, ans;
int a[N];

int main() {
    scanf("%d %llf", &n, &S);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    
    long double avg = S / n;
    for (int i = 0; i < n; ++i) {
        long double cur = S / (n - i);
        if (a[i] < cur) cur = a[i];
        ans += (cur - avg) * (cur - avg);
        S -= cur;
    }
    printf("%.4llf", sqrt(ans / n));
}
