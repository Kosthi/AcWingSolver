#include <iostream>
#include <algorithm>

using namespace std;

int a[11];

bool cmp(int a, int b) {
    if (a % 2 && b % 2) return a > b;
    else if (a % 2 == 0 && b % 2 == 0) return a < b;
    else if (a % 2) return true;
    return false;
}

int main() {
    for (int i = 0; i < 10; ++i) cin >> a[i];
    sort(a, a + 10, cmp);
    for (int i = 0; i < 10; ++i) cout << a[i] << " ";
}
