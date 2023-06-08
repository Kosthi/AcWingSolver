#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const int N = 500010;

typedef long long LL;

int k;
string s;
char a, c;
vector<int> s1, s2;
int cnt1, cnt2;
LL ans;

int main() {
    scanf("%d", &k);
    cin >> s >> a >> c;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == a) s1.push_back(i);
        if (s[i] == c) s2.push_back(i);
    }
    for (int i = 0; i < s1.size(); ++i) {
        int t = s1[i];
        int l = 0, r = s2.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (s2[mid] - t + 1 >= k) r = mid;
            else l = mid + 1;
        }
        if (s2[r] - t + 1 >= k) ans += s2.size() - r;
    }
    printf("%lld", ans);
}
