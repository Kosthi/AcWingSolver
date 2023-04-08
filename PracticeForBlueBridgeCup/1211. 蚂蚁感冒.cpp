#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50;

int n, i, k, cnt = 1;
int a[N];

bool cmp(int a, int b) {
    return abs(a) < abs(b);
}

int main() {
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int tmp = a[0];
    sort(a, a + i, cmp);
    
    for (k = 0; k < n; ++k) {
        if (a[k] == tmp) break;
    }
    
    if (tmp > 0) {
        for (int j = k + 1; j < n; ++j) {
            if (a[j] < 0) cnt++;
        }
        if (cnt != 1) {
            for (int j = k - 1; j >= 0; --j) {
                if (a[j] > 0) cnt++;
            }
        }
    }
    else {
         for (int j = k - 1; j >= 0; --j) {
            if (a[j] > 0) cnt++;
        }
        if (cnt != 1) {
            for (int j = k + 1; j <= n; ++j) {
                if (a[j] < 0) cnt++;
            }
        }
    }
    cout << cnt << endl;
}

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50;

int n, l, r;
int a[N];


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i < n; ++i) {
        if (abs(a[i]) < abs(a[0]) && a[i] > 0) l++;
        else if (abs(a[i]) > abs(a[0]) && a[i] < 0) r++;
    }
    if (a[0] > 0 && r > 0 || a[0] < 0 && l > 0) {
        cout << l + r + 1 << endl;
    }
    else {
        cout << 1 << endl;
    }
}
