#include <iostream>
#include <vector>

using namespace std;

const int N = 100010, M = 110;

int n, m, k, kk;
vector<int> a[N];
int b[M];
int cur = 1;
int xx, yy;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j) {
            scanf("%d", &kk);
            a[i].push_back(kk);
        }
    }
    while (m--) {
        scanf("%d %d", &xx, &yy);
        if (xx == 1) {
            b[yy] = cur;
            printf("%d\n", cur);
        }
        else if (xx == 2) {
            cur = b[yy];
        }
        else {
            cur = a[cur][yy - 1];
        }
    }
    printf("%d\n", cur);
}
