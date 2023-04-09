#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, k, g;
int cnt, st[300];

struct S {
    int t, p;
    bool operator<(const S& s) const {
        if (t == s.t) return p > s.p;
        return t > s.t;
    }
}s[N];

int main() {
    cin >> n >> k >> g;
    for (int i = 0; i < n; ++i) {
        cin >> s[i].t >> s[i].p;
        st[s[i].t]++;
    }
    sort(s, s + n);
    for (int i = 0; i < n; ++i) {
        if (s[i].t >= 175 && s[i].p >= g) {
            cnt++;
            st[s[i].t]--;
        }
    }
    for (int i = 290; i >= 175; --i) {
        if (st[i]) cnt += min(k, st[i]);
    }
    cout << cnt << endl;
}
