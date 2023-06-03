#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 12, M = 1 << N;

typedef long long LL;

int n, m;
bool st[M];
vector<int> state[M];
LL f[N][M];

int main() {
    while (cin >> n >> m, n || m) {
        memset(st, 0, sizeof st);
        for (int i = 0; i < 1 << n; ++i) {
            int cnt = 0;
            bool is_vaild = true;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    if (cnt & 1) {
                        is_vaild = false;
                        break;
                    }
                    cnt = 0;
                }
                else cnt++;
            }
            if (cnt & 1) is_vaild = false;
            st[i] = is_vaild;
        }
        
        for (int i = 0; i < 1 << n; ++i) {
            state[i].clear();
            for (int k = 0; k < 1 << n; ++k) {
                if ((i & k) == 0 && st[i | k])
                    state[i].push_back(k);
            }
        }
        
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                for (auto k : state[j])
                    f[i][j] += f[i - 1][k];
            }
        }
        
        printf("%lld\n", f[m][0]);
    }
}
