#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define x first
#define y second

using namespace std;

const int N = 100010;

typedef pair<int, int> PII;
PII logs[N];
bool st[N];
int cnt[N];

int n, d, k;

int main() {
    scanf("%d %d %d", &n, &d, &k);
    
    for (int i = 0; i < n; ++i) scanf("%d %d", &logs[i].x, &logs[i].y);
    
    sort(logs, logs + n);
    
    for (int i = 0, j = 0; i < n; ++i) {
        int id = logs[i].y;
        cnt[id]++;
        
        while (logs[i].x - logs[j].x >= d) {
            cnt[logs[j].y]--;
            j++;
        }
        
        if (cnt[id] >= k) st[id] = true;
        
    }
    
    for (int i = 0; i < N; ++i) {
        if (st[i])
            printf("%d\n", i);
    }
}
