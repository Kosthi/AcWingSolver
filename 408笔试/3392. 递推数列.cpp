#include <iostream>

using namespace std;

int a1, a2;
int p, q, k;

int main() {
    int ans;
    cin >> a1 >> a2 >> p >> q >> k;
    for (int i = 0; i < k - 1; ++i) {
        ans = (p * a2 + q * a1) % 10000;
        a1 = a2;
        a2 = ans;
    }
    cout << ans % 10000 << endl;
}
