#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

LL x, y;

int main() {
    cin >> x >> y;
    if (abs(x) <= y) {
        cout << (LL)(2 * abs(y)) * (2 * abs(y) - 1) + y + x;
    }
    else if (abs(y) <= x) {
        cout << (LL)(2 * abs(x)) * (2 * abs(x)) + x - y;
    }
    else if (abs(x) <= -y + 1) {
        cout << (LL)(2 * abs(y)) * (2 * abs(y) + 1) + abs(y + x);
    }
    else {
        cout << (LL)(2 * abs(x) - 1) * (2 * abs(x) - 1) + y - (x + 1);
    }
}

#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

int x, y;

int main() {
    cin >> x >> y;
    LL k = max(abs(x), abs(y));
    if (x >= y) cout << 4 * k * k + abs(x - k) + abs(y - k);
    else cout << 4 * k * k - abs(x - k) - abs(y - k);
}

