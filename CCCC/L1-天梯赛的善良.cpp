#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20010, M = 1000010;

int a[N], h[M];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        h[a[i]]++;
    }
    sort(a, a + n);
    cout << a[0] << " " << h[a[0]] << endl;
    cout << a[n - 1] << " " << h[a[n - 1]] << endl;
}
