#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10010;

vector<int> v[N];

int n, k, m;
int ans, head;
int st[N];
vector<int> way;

bool check(vector<int>& w) {
    for (int i = 0; i < w.size(); ++i) {
        if (w[i] > way[i]) return false;
        else if (w[i] < way[i]) return true;
    }
}

void dfs(int s, int u, vector<int>& w) {
    if (!v[u].size()) {
        if (ans < s || (way.size() && ans == s && check(w))) {
            ans = s;
            way = w;
        }
        return;
    }
    for (int i = 0; i < v[u].size(); ++i) {
        w.push_back(v[u][i]);
        dfs(s + 1, v[u][i], w);
        w.pop_back();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        while (k--) {
            cin >> m;
            v[i].push_back(m);
            st[m] = 1;
        }
        // sort(v[i].begin(), v[i].end()); // 字典序排序
    }
    int root = 0;
    while (st[root]) root++; // 没有父节点的必然是根
    vector<int> w;
    dfs(1, root, w);
    printf("%d\n%d", ans, root);
    for (auto& w : way) printf(" %d", w);
}
