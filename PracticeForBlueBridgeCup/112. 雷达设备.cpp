#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1010;

int n, d;
int x, y, ans;

struct Segment {
    double l, r;
    bool operator<(const Segment& s) const {
        return r < s.r;
    }
}segment[N];

int main() {
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        if (y > d) {
            puts("-1");
            return 0;
        }
        double dealt = sqrt(d * d - y * y);
        segment[i].l = x - dealt;
        segment[i].r = x + dealt;
    }
    sort(segment, segment + n);
    
    double r = segment[0].r;
    for (int i = 1; i < n; ++i) {
        if (segment[i].l > r) {
            ans++;
            r = segment[i].r;
        }
    }
    printf("%d", ans + 1);
}
