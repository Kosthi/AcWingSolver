#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 30;

int n;
char arr[N][N], backup[N][N];
int dx[] = {-1, 0, 1, 0, 0}, dy[] = {0, 1, 0, -1, 0};


void turn(int a, int b) {
    for (int i = 0; i < 5; ++i) {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x < 0 || x >= 5 || y < 0 || y >= 5) continue;
        arr[x][y] ^= 1;
    }
}

int main() {
    cin >> n;
    while (n--) {
        for (int i = 0; i < 5; ++i) {
            scanf("%s", arr[i]);
        }
        int minstep = 30;
        memcpy(backup, arr, sizeof arr);
        for (int i = 0; i < 32; ++i) {
            int step = 0;
            for (int j = 0; j < 5; ++j) {
                if (i >> j & 1) {
                    step++;
                    turn(0, j);
                }
            }
            
            for (int u = 0; u < 4; ++u) {
                for (int k = 0; k < 5; ++k) {
                    if (arr[u][k] == '0') {
                        step++;
                        turn(u + 1, k);
                    }
                }
            }
            bool flag = true;
            for (int i = 0; i < 5; ++i) {
                if (arr[4][i] == '0') {
                    flag = false;
                    break;
                }
            }
            
            if (flag) {
                minstep = min(minstep, step);
            }
            memcpy(arr, backup, sizeof backup);
        }
        if (minstep > 6) minstep = -1;
        printf("%d\n", minstep);
    }
}
