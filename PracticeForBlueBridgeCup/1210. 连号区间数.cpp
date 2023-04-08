#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5;

int n, cnt;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        int maxl = 0, minl = INT32_MAX;
        for (int j = i; j < n; ++j) {
            maxl = max(maxl, a[j]);
            minl = min(minl, a[j]);
            if (j - i == maxl - minl) cnt++;
        }
    }
    cout << cnt << endl;
}
