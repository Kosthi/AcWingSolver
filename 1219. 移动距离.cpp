#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int w, m, n;

int main() {
    cin >> w >> m >> n;
    int x1 = (m - 1) / w, x2 = (n - 1) / w;
    int y1 = x1 % 2 ? w - (m - 1) % w - 1: (m - 1) % w;
    int y2 = x2 % 2 ? w - (n - 1) % w - 1: (n - 1) % w;
    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
}
