#include <iostream>

using namespace std;

const int N = 10010;

int n;
int a[N], cir;
bool st[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
        if (!st[i]) {
            cir++;
            for (int j = i; !st[j]; j = a[j])
                st[j] = true;
        }
    }
    cout << n - cir << endl;
}
