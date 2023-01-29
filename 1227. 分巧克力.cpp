#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5;

int n, k;
int H[N], W[N];


bool check(int side) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += (H[i] / side) * (W[i] / side);
        if (s >= k) return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> H[i] >> W[i];
    }
    
    int l = 1, r = N;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << endl;
    return 0;
}
