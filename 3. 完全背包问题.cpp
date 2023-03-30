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
