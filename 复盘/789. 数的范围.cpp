#include <cstdio>
#include <cstring>

const int N = 100010;

int a[N];
int n, q, num;

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    while (q--) {
        scanf("%d", &num);
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] >= num) r = mid;
            else l = mid + 1;
        }
        if (a[r] != num) {
            puts("-1 -1");
            continue;
        }
        printf("%d ", r);
        
        l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (a[mid] <= num) l = mid;
            else r = mid - 1;
        }
        printf("%d\n", r);
    }
}
