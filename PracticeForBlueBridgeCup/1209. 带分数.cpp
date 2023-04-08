#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;

int n;
int used[N], backup[N];
int ans;


bool check(int a, int c) {
    int b = c * (n - a);
    if (b <= 0) return false;
    memcpy(backup, used, sizeof used);
    
    while (b) {
        int x = b % 10;
        if (backup[x] || !x) return false;
        backup[x] = true;
        b /= 10;
    }
    
    for (int i = 1; i <= 9; ++i) {
        if (!backup[i]) return false;
    }
    
    return true;
}

void dfs_c(int u, int a, int c) {
    if (u > 7) return;
    if (check(a, c)) ans++;
    for (int i = 1; i <= 9; ++i) {
        if (!used[i]) {
            used[i] = true;
            dfs_c(u + 1, a, c * 10 + i);
            used[i] = false;
        }
    }
}

void dfs_a(int u, int a) {
    if (a >= n) return;
    if (a) dfs_c(u, a, 0);
    
    for (int i = 1; i <= 9; ++i) {
        if (!used[i]) {
            used[i] = true;
            dfs_a(u + 1, a * 10 + i);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs_a(0, 0);
    printf("%d", ans);
    return 0;
}
