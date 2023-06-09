// 二分
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

// fix bug scanf
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 500010;

typedef long long LL;

int n, k;
char s[N], a, c;
int s1[N], s2[N];
int cnt1, cnt2;
LL ans;

int main() {
    scanf("%d", &k);
    scanf("%s %c %c", s, &a, &c);
    
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == a) s1[cnt1++] = i;
        if (s[i] == c) s2[cnt2++] = i;
    }
    
    for (int i = 0; i < cnt1; ++i) {
        int t = s1[i];
        int l = 0, r = cnt2 - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (s2[mid] - t + 1 >= k) r = mid;
            else l = mid + 1;
        }
        if (s2[r] - t + 1 >= k) ans += cnt2 - r;
    }
    printf("%lld", ans);
}

// 前缀和
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 500010;

typedef long long LL;

int k;
string s;
char a, c;
int cnt, st[N];
LL ans;

int main() {
    scanf("%d", &k);
    cin >> s >> a >> c;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == a) cnt++;
        st[i] = cnt;
        if (s[i] == c && i - k + 1 >= 0) ans += st[i - k + 1];
    }
    printf("%lld", ans);
}

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 500010;

typedef long long LL;

int k;
string s;
char a, c;
int cnt;
LL ans;

int main() {
    scanf("%d", &k);
    cin >> s >> a >> c;
    for (int i = 0; i < s.size(); ++i) {
        if (i - k + 1 >= 0 && s[i - k + 1] == a) cnt++;
        if (s[i] == c) ans += cnt;
    }
    printf("%lld", ans);
}
