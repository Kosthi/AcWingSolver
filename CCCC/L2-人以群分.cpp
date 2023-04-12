#include <iostream>
#include <algorithm>

const int N = 100010;

using namespace std;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int s1 = 0, s2 = 0;
    if (n % 2 == 0) {
        cout << "Outgoing #: " << n / 2 << endl;
        cout << "Introverted #: " << n / 2 << endl;
        for (int i = 0; i < n / 2; ++i) s1 += a[i];
        for (int i = n / 2; i < n; ++i) s2 += a[i];
        cout << "Diff = " << s2 - s1 << endl;
    }
    else {
        cout << "Outgoing #: " << n - n / 2 << endl;
        cout << "Introverted #: " << n / 2 << endl;
        for (int i = 0; i < n / 2; ++i) s1 += a[i];
        for (int i = n / 2; i < n; ++i) s2 += a[i];
        cout << "Diff = " << s2 - s1 << endl;
    }
}
