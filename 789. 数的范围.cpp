#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 1;
int n, q, aim;
int a[N];


int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    while (q--) {
        scanf("%d", &aim);
        
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] >= aim) r = mid;
            else l = mid + 1;
        }
        if (a[r] == aim) {
            printf("%d ", r);
            r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (a[mid] <= aim) l = mid;
                else r = mid - 1;
            }
            printf("%d\n", r);
        }
        else {
            printf("-1 -1\n");
        }
    }
}
