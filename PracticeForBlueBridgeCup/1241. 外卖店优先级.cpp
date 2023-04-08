#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6;

int n, m, t;

PII order[N];
int st[N], score[N], last[N];

int main() {
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 0; i < m; ++i) scanf("%d %d", &order[i].x, &order[i].y);
    
    sort(order, order + m);
    
    for (int i = 0; i < m;) {
        int j = i;
        while (j < m && order[j] == order[i]) ++j;
        int t = order[i].x, id = order[i].y, cnt = j - i;
        i = j;
        
        score[id] -= t - last[id] - 1;
        if (score[id] < 0) score[id] = 0;
        if (score[id] <= 3) st[id] = 0;
        
        score[id] += 2 * cnt;
        if (score[id] > 5) st[id] = 1;
        last[id] = t;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (last[i] < t) {
            score[i] -= t - last[i];
            if (score[i] <= 3) st[i] = 0;
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (st[i]) res++;
    }
    
    cout << res << endl;
}
