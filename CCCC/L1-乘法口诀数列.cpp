#include <iostream>

using namespace std;

const int N = 2010;

int a1, a2, n;
int h[N], cnt = 2;

int main() {
    cin >> a1 >> a2 >> n;
    h[0] = a1;
    h[1] = a2;
    for (int i = 0; i < n; ++i) {
        int m = h[i] * h[i + 1];
        string tp = to_string(m);
        for (int i = 0; i < tp.size(); ++i)
            h[cnt++] = tp[i] - '0';
    }
    for (int i = 0; i < n; ++i) {
        if (i != n - 1) cout << h[i] << " ";
        else cout << h[i] << endl;
    }
}
