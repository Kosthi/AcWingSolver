#include <cstdio>

const int N = 100010;

int n;
int H[N];
int maxx;

bool check(int e) {
    for (int i = 0; i < n; ++i) {
        // e会上溢 LL也放不下
        e = 2 * e - H[i + 1];
        if (e < 0) return false;
        if (e > N) return true;
    }
    return e >= 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &H[i]);
        if (maxx < H[i]) maxx = H[i]; 
    }
    int l = 1, r = maxx;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d", r);
}
