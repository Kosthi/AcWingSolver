#include <iostream>

int n, k, ans;

using namespace std;

int main() {
    cin >> n;
    while (n--) {
        cin >> k;
        ans ^= k;
    }
    if (!ans) cout << "No" << endl;
    else cout << "Yes" << endl;
}
