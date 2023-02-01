#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int k = i;
        while (k) {
            int x = k % 10;
            if (x == 1 || x == 2 || x == 0 || x == 9) {
                sum += i;
                break;
            }
            k /= 10;
        }
    }
    cout << sum << endl;
}
