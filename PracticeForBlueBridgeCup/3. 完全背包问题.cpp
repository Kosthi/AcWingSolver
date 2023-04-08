#include <iostream>

using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int dp[N];

int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; ++i)
        for (int j = v[i]; j <= V; ++j)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[V] << endl;
}
// 1-D
#include <iostream>

using namespace std;

const int N = 1010;

int n, V;
int v, w;
int dp[N];

int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> v >> w;
        for (int j = v; j <= V; ++j)
        // dp[i][j] = max(dp[i - 1][j], dp[i][j - v] + w)
        // 使用更新后的i行的价值，而不是i - 1，所以降维后应该从小到大枚举体积，确保比较的是更新后的i
            dp[j] = max(dp[j], dp[j - v] + w);
    }
    cout << dp[V] << endl;
}
