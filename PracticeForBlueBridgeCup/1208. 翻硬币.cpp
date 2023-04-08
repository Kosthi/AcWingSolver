#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str1, str2;
int cnt;


void dfs(int u) {
    if (str1 == str2) {
        return;
    }
    if (str1[u] != str2[u]) {
        str1[u] = str1[u] == '*' ? 'o' : '*';
        str1[u + 1] = str1[u + 1] == '*' ? 'o' : '*';
        dfs(u + 1);
        cnt++;
    }
    else {
        dfs(u + 1);
    }
}

int main() {
    cin >> str1 >> str2;
    dfs(0);
    cout << cnt << endl;
    return 0;
}
