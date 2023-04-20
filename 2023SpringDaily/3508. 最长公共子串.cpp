#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 20010, P = 131;

typedef unsigned long long ULL;

int n, m;
char s[N];
ULL h[N], p[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

bool check(int k) {
    unordered_set<ULL> hash;
    for (int i = 1; i <= n - k + 1; ++i) {
        hash.insert(get(i, i + k - 1));
    }
    for (int i = n + 1; i <= n + m - k + 1; ++i) {
        if (hash.count(get(i, i + k - 1))) return true;
    }
    return false;
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    scanf("%s", s + n + 1);
    m = strlen(s + n + 1);
    
    p[0] = 1;
    for (int i = 1; i <= n + m; ++i) {
        p[i] = p[i - 1] * P;
        if (isdigit(s[i])) {
            if (i <= n) s[i] = '$';
            else s[i] = '&';
        }
        h[i] = h[i - 1] * P + s[i];
    }
    
    int l = 0, r = min(n, m);
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    
    cout << r << endl;
}
