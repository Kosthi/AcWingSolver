#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, p;
int a[N];
int res;

int main() {
    cin >> n >> p;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = 0, j = 0; j < n; ++j) {
        while (a[j] > p * a[i]) i++;
        res = max(res, j - i + 1);
    }
    cout << res << endl;
}
