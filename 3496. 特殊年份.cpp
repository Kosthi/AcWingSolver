#include <iostream>

using namespace std;

int k = 5, cnt, n;
int a[4];

int main() {
    while (k--) {
        cin >> n;
        int i = 0;
        while (n) {
            int p = n % 10;
            a[i++] = p;
            n /= 10;
        }
        if (a[1] == a[3] && a[0] - 1 == a[2]) cnt++;
    }
    cout << cnt << endl;
}
