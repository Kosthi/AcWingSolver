#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int f[50];

int main() {
    cin >> n;
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    
    for (int i = 1; i <= n; ++i) {
        printf("%d ", f[i]);
    }
    puts("");
}
