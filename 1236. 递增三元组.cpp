// 前缀和
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
LL sum;
int a[N], b[N], c[N];
int sa[N], sc[N];

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sa[a[i]]++;
    }
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
        sc[c[i]]++;
    }
    
    for (int i = 1; i < N; ++i) {
        sa[i] += sa[i - 1];
        sc[i] += sc[i - 1];
    }
    
    for (int i = 0; i < n; ++i) {
        sum += (LL)(sa[b[i] - 1]) * (sc[N - 1] - sc[b[i]]);
    }
    cout << sum << endl;
}

// 二分
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
LL sum;
int a[N], b[N], c[N];
int sa[N], sc[N];

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sa[a[i]]++;
    }
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
        sc[c[i]]++;
    }
    
    sort(a, a + n);
    sort(c, c + n);
    
    int t, g;
    for (int i = 0; i < n; ++i) {
        
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] >= b[i]) r = mid;
            else l = mid + 1;
        }
        // 没找到大于等于bi
        if (a[r] < b[i]) t = n;
        else t = r;
        
        l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (c[mid] <= b[i]) l = mid;
            else r = mid - 1;
        }
        // 没找到小于等于bi
        if (c[r] > b[i]) g = n;
        else g = n - (r + 1);
        
        sum += (LL)t * g;
    }
    cout << sum << endl;
}
