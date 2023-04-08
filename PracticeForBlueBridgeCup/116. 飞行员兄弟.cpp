#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 5;
char arr[N][N];
int cnt;
string ans;


bool check(int i, int j) {
    int cnt = 0;
    for(int k = -3; k <= 3; ++k) {
        int x = i, y = j + k;
        if (x < 0 || x >= 4 || y < 0 || y >= 4) continue;
        if (arr[x][y] == '+') cnt++;
    }
    for(int k = -3; k <= 3; ++k) {
        int x = i + k, y = j;
        if (x < 0 || x >= 4 || y < 0 || y >= 4 || k == 0) continue;
        if (arr[x][y] == '+') cnt++;
    }
    if (cnt % 2) return true;
    return false;
}

int main() {
    for (int i = 0; i < 4; ++i) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (check(i, j)) {
                char a = i + '0' + 1, b = j + '0' + 1;
                ans += a;
                ans += ' ';
                ans += b;
                ans += '\n';
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    cout << ans;
}
