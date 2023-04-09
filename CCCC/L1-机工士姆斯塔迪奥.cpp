#include <iostream>

using namespace std;

const int N = 100010;

int n, m, cnt;
int q, st[N];

int main() {
    cin >> n >> m >> q;
    int k, p;
    while (q--) {
        cin >> k >> p;
        if (k == 0) {
            for (int i = 1; i <= m; ++i)
                st[(p - 1) * m + i]= 1;
        }
        else if (k == 1) {
            for (int i = 1; i <= n; ++i)
                st[p + (i - 1) * m] = 1;
        }
    }
    for (int i = 1; i <= n * m; ++i)
        if (!st[i]) cnt++;
    cout << cnt << endl;
}
