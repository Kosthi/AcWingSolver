#include <iostream>

using namespace std;

int a[24], k;

int main() {
    for (int i = 0; i < 24; ++i) {
        cin >> a[i];
    }
    while (cin >> k && k >= 0 && k <= 23) {
        if (a[k] > 50) cout << a[k] << " Yes" << endl;
        else cout << a[k] << " No" << endl;
    }
}
