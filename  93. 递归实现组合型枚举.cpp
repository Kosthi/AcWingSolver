#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1 << 15;

int n, m;
int sta[N + 1];
// bool used[N + 1];


void dfs(int k) {
    if (k > m) {
        for (int i = 1; i <= m; ++i) {
            printf("%d ", sta[i]);
        }
        puts("");
        return;
    }
    for (int i = k; i <= n - m + k; ++i) {
        if (i > sta[k - 1]) {
            sta[k] = i;
            //used[i] = true;
            dfs(k + 1);
            //used[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}
