#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N];


int main() {
    cin >> n;
    for (int r = 2; r <= n; r++) {
        scanf("%d", &a[r]);
        for (int l = 1; l < r; ++l) {
            if (a[l] < a[r]) {
                f[r] = max(f[r], f[l] + 1);
            }
        }
	f[0] = max(f[0], f[r]);
    }
    cout << f[0] + 1 << endl;
}
