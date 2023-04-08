#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 9;

int n;
int sta[N + 1];
bool used[N + 1];


void dfs(int k) {
    if (k > n) {
        for (int i = 1; i <= n; ++i) {
            printf("%d ", sta[i]);
        }
        puts("");
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            sta[k] = i;
            used[i] = true;
            dfs(k + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}
