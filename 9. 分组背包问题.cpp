#include <iostream>

using namespace std;

const int N = 110;

int n, V, k;
int v[N][N], w[N][N], nums;
int dp[N];

int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> nums;
        for (int j = 1; j <= nums; ++j) cin >> v[i][j] >> w[i][j];
        for (int j = V; j >= 1; --j)
            for (int k = 1; k <= nums; ++k)
                if (j >= v[i][k])
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
    }
    cout << dp[V] << endl;
}
// Memory Optimize
#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int n, V, k;
int v, w, nums;
int dp[N], last[N];

int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> nums;
        for (int j = 1; j <= nums; ++j) {
            cin >> v >> w;
            for (int j = V; j >= v; --j)
                dp[j] = max(dp[j], last[j - v] + w);
        }
        // 使用last数组保留里上一个dp数组，等效于dp[i - 1][j - v].
        // 故可以在内部遍历体积。
        memcpy(last, dp, sizeof dp);
    }
    cout << dp[V] << endl;
}
