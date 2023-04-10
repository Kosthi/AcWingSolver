#include <iostream>

using namespace std;

int n;
char ch;

int main() {
    cin >> n >> ch;
    if (n == 1) {
        cout << ch << endl << 0 << endl;
        return 0;
    }
    int t = n - 1, p = 3;
    while (t > 0) {
        t -= 2 * p;
        p += 2;
    }
    p -= 2;
    t += 2 * p;
    p -= 2;
    for (int i = 0; i < p; i += 2) {
        for (int k = 0; k < i / 2; ++k) cout << " ";
        for (int j = 0; j < p - i; ++j) cout << ch;
        puts("");
    }

    for (int i = 3; i <= p; i += 2) {
        for (int k = 0; k < (p - i) / 2; ++k) cout << " ";
        for (int j = 0; j < i; ++j) cout << ch;
        puts("");
    }

    cout << t;
}
