#include <iostream>

using namespace std;

const int N = 11010, M = 2010;

int n, V;
int v[N], w[N];
int dp[M];
int v_, w_, s_;

int main() {
    int cnt = 0;
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> v_ >> w_ >> s_; // v w s
        for (int k = 1; k <= s_; k *= 2) {
            cnt++;
            v[cnt] = v_ * k;
            w[cnt] = w_ * k;
            s_ -= k;
        }
        if (s_ > 0) {
            cnt++;
            v[cnt] = v_ * s_;
            w[cnt] = w_ * s_;
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        for (int j = V; j >= v[i]; --j)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    }
    cout << dp[V] << endl;
}
