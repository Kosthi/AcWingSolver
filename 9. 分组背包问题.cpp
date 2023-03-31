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
