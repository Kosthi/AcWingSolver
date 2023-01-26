#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15;

int n;
int sta[N + 1], cnt;


void dfs(int k) {
    if (k > n) {
        for (int i = 1; i <= n; i++) {
            if (sta[i]) {
                printf("%d ", i);
            }
        }
        puts("");
        cnt++;
        return;
    }

    sta[k] = 0;
    dfs(k + 1);

    sta[k] = 1;
    dfs(k + 1);
}

int main() {
    cin >> n;
    dfs(1);
    printf("%d", cnt);
    return 0;
}
