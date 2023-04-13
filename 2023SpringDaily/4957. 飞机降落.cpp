#include <iostream>

using namespace std;

const int N = 10010;

typedef long long LL;

int n;
int a[N], b[N];
int maxx = INT32_MAX;

bool check(int k) {
    for (int i = 0; i < n; ++i) {
        if (a[i] / k != b[i]) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        maxx = min(maxx, a[i] / b[i]);
    }
    int l = 1, r = maxx;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << " ";
    l = maxx, r = 1000000000;
    while (l < r) {
        LL mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << endl;
}
