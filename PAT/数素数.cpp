#include <iostream>

using namespace std;

typedef long long  LL;

const int N = 10010;

int prime[N];

int n, m;

int main() {
    cin >> n >> m;
    int p = 0, cnt = 0;
    int i = 2;
    while (cnt < m) {
        int j = 2;
        for (; j * j <= i; ++j) if (i % j == 0) break;
        if (j * j > i) {
            cnt++;
            if (cnt >= n) prime[p++] = i;
        }
        i++;
    }
    for (int k = 0; k < p; ++k) {
        if ((k + 1) % 10 == 0) cout << prime[k] << endl;
        else if (k == p - 1) cout << prime[k];
        else cout << prime[k] << " ";
    }
}
