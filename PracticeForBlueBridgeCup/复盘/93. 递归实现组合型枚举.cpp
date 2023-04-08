#include <iostream>

using namespace std;

int n, m;
int st[50], used[50];

void dfs(int u) {
    if (u > m) {
        for (int i = 1; i <= m; ++i) {
            printf("%d ", st[i]);
        }
        puts("");
        return;
    }
    // 极致剪枝 n=3时，第1位在1-3中选，第2位数在2-4中选，第3位数在3-5中选。
    for (int i = u; i <= n - m + u; ++i) {
        if (!used[i] && st[u - 1] < i) {
            st[u] = i;
            used[i] = 1;
            dfs(u + 1);
            used[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(1);
}
