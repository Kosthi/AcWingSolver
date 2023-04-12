#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int h[N], sz;

void down(int u) {
    int t = u;
    if (2 * u <= sz && h[2 * u] < h[t]) t = 2 * u;
    if (2 * u + 1 <= sz && h[2 * u + 1] < h[t]) t = 2 * u + 1;
    if (u != t) {
        swap(h[u], h[t]);
        down(t);
    }
}

int main() {
    cin >> n >> m;
    sz = n;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = n / 2; i; --i) down(i);
    while (m--) {
        cout << h[1] << " ";
        h[1] = h[sz];
        sz--;
        down(1);
    }
}
