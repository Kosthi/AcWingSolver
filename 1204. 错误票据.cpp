#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

const int N = 10010;

int m, n, l;
int a[N];


int main() {
    cin >> l;
    int i = 0;
    string str;
    getline(cin, str);
    while (l--) {
        getline(cin, str);
        stringstream ssin(str);
        while (ssin >> a[i]) i++;
    }
    sort(a, a + i);
    for (int k = 0; k < i; ++k) {
        if (a[k] == a[k + 1]) n = a[k];
        if (a[k] + 1 < a[k + 1]) m = a[k + 1] - 1;
    }
    cout << m << " " << n << endl;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

const int N = 10010;

int m, n, l;
int a[N];
bool st[100010];

int main() {
    cin >> l;
    int i = 0;
    string str;
    getline(cin, str);
    while (l--) {
        getline(cin, str);
        stringstream ssin(str);
        while (ssin >> a[i]) {
            if (!st[a[i]]) st[a[i]] = true;
            else n = a[i];
            i++;
        }
    }
    i = 0;
    while (!st[++i]);
    for (int k = i; ; ++k) {
        if (!st[k]) {
            m = k;
            break;
        }
    }
    cout << m << " " << n << endl;
}
