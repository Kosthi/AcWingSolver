#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 210;

int T, n;
string str, tmp;

void turn(int i) {
    tmp[i] = tmp[i] == 'W' ? 'B' : 'W';
    tmp[i + 1] = tmp[i + 1] == 'W' ? 'B' : 'W';
}

bool check(char c) {
    tmp = str;
    vector<int> ans;
    for (int i = 0; i + 1 < n; ++i) {
        if (tmp[i] != c) {
            ans.push_back(i + 1);
            turn(i);
        }
    }
    if (tmp[n - 1] != c) return false;
    else {
        printf("%d\n", ans.size());
        for (int x : ans) printf("%d ", x);
        if (ans.size()) puts("");
    }
    return true;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> str;
        if (!check('W') && !check('B')) puts("-1");
    }
}
