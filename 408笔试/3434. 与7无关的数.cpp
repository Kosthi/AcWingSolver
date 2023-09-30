#include <iostream>

using namespace std;

int n, s;

bool check(int n) {
    if (n % 7 == 0) return true;
    while (n) {
        int k = n % 10;
        if (k == 7) return true;
        n /= 10;
    }
    return false;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        if (!check(i)) s += i * i;
    }
    cout << s << endl;
}
