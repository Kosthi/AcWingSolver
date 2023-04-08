#include <iostream>
#include <cstring>

using namespace std;

string s;
int n;
int h[10];

int main() {
    for (int i = 0; i < 10; ++i) {
        cin >> n;
        h[i] = n;
    }
    int i;
    for (i = 1; i < 10; ++i) {
        if (h[i]) break;
    }
    cout << i;
    h[i]--;
    for (i = 0; i < 10; ++i) {
        while (h[i]--) cout << i;
    }
}
