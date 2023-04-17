#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#define x first
#define y second

using namespace std;

const int N = 10010;

typedef pair<int, vector<int>> PII;

int n, m, k, cnt;
map<vector<int>, int> mp;
vector<PII> v;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        vector<int> v;
        for (int j = 0; j < m; ++j) {
            scanf("%d", &k);
            v.push_back(k);
        }
        mp[v]++;
    }
    for (auto it : mp) v.push_back({-it.y, it.x});
    sort(v.begin(), v.end());
    printf("%d\n", mp.size());
    for (auto [key, value] : v) {
        printf("%d ", -key);
        for (int i = 0; i < value.size(); ++i) {
            if (i != value.size() - 1) printf("%d ", value[i]);
            else printf("%d\n", value[i]);
        }
    }
}
