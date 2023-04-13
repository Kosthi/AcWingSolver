#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 20;

int T, n;
int t[N], d[N], l[N], st[N];
int flag;

void dfs(int u, int ll) {
	if (u == n) {
		flag = 1;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!st[i] && t[i] + d[i] >= ll) {
		    st[i] = 1;
		    dfs(u + 1, max(ll, t[i]) + l[i]);
		    st[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		flag = 0;
		for (int i = 1; i <= n; ++i) scanf("%d %d %d", &t[i], &d[i], &l[i]);
		dfs(0, 0);
		if (flag) puts("YES");
		else puts("NO");
	}
}
