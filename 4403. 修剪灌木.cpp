#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << max(2 * (n - i), 2 * (i - 1)) << endl;;
    }
}
