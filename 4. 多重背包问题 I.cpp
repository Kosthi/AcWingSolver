#include <iostream>

using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N], s[N];
int dp[N];

int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i] >> s[i];
        for (int j = V; j >= v[i]; --j)
            for (int k = 0; k <= s[i] && k * v[i] <= j; ++k)
                dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
    }
    cout << dp[V] << endl;
}
