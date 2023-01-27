#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int f(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    return f(n - 1) + f(n - 2);
}

int main() {
    cin >> n;
    printf("%d", f(n));
}

// 递归大于41超时，递推大于46超时
