#include <iostream>

using namespace std;

double n, m, p;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        if (p < m) printf("On Sale! %.1lf\n", p);
    }
}
