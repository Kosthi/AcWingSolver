#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int n, ans;

int main() {
    cin >> n;
    while (n != 1) {
        ans++;
        if (n % 2 == 0) n /= 2;
        else n = (n * 3 + 1) / 2;
    }
    cout << ans << endl;
}
