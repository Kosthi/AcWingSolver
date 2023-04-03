#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 510;

int n;
char a[10][10], backup[10][10];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void turn(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx > 4 || yy < 0 || yy > 4) continue;
        a[xx][yy] ^= 1;
    }
    a[x][y] ^= 1;
}

bool check() {
    for (int i = 0; i < 5; ++i)
        if (a[4][i] == '0') return false;
    return true;
}

int main() {
    scanf("%d", &n);
    while (n--) {
        for (int i = 0; i < 5; ++i) scanf("%s", a[i]);
        int minstep = 30;
        // 第一行决定结果，枚举所有可能的初始状态 32种
        for (int i = 0; i < 32; ++i) {
            int step = 0;
            memcpy(backup, a, sizeof a);
            for (int j = 0; j < 5; ++j) {
                if (i >> j & 1) {
                    step++;
                    turn(0, j);
                }
            }
            
            for (int u = 0; u < 4; ++u) {
                for (int k = 0; k < 5; ++k) {
                    if (a[u][k] == '0') {
                        step++;
                        turn(u + 1, k);
                    }
                } 
            }
            
            if (check()) minstep = std::min(minstep, step);
            memcpy(a, backup, sizeof a);
        }
        if (minstep > 6) minstep = -1;
        printf("%d\n", minstep);
    }
}
