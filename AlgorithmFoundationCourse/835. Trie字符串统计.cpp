#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int son[N][26], cnt[N], idx;
string op, w;

void insert(string w) {
    int p = 0;
    for (int i = 0; w[i]; ++i) {
        int c = w[i] - 'a';
        if (!son[p][c]) son[p][c] = ++idx;
        p = son[p][c];
    }
    cnt[p]++;
}

int query(string w) {
    int p = 0;
    for (int i = 0; w[i]; ++i) {
        int c = w[i] - 'a';
        if (!son[p][c]) return 0;
        p = son[p][c];
    }
    return cnt[p];
}

int main() {
    scanf("%d", &n);
    while (n--) {
        cin >> op >> w;
        if (op == "I") insert(w);
        else printf("%d\n", query(w));
    }
}
