#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5;

int n, maxh;
int a[N];


bool check(int energy) {
    for (int i = 0; i < n; ++i) {
        energy = 2 * energy - a[i];
        if (energy < 0) return false;
        if (energy >= maxh) return true;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        maxh = max(maxh, a[i]);
    }
    
    int l = 1, r = maxh;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", r);
}
