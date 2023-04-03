#include <cstdio>
#include <cstring>

const int N = 1000010;

int n, cnt;
int used[10], backup[10]; 

bool check(int a, int c) {
    int b = c * (n - a);
    if (b <= 0) return false;
    memcpy(backup, used, sizeof used);
    // 重复数字
    while (b) {
        int k = b % 10;
        if (backup[k] || !k) return false;
        backup[k] = 1;
        b /= 10;
    }
    // 是否都用过
    for (int i = 1; i <= 9; ++i) {
        if (!backup[i]) return false;
    }
    return true;
}

// 枚举a、c，因为都大于0，最多7位
void dfs_c(int u, int v, int a) {
    if (u > 7) return;
    if (v && check(a, v) ) cnt++;
    
    for (int i = 1; i <= 9; ++i) {
        if (!used[i]) {
            used[i] = 1;
            dfs_c(u + 1, v * 10 + i, a);
            used[i] = 0;
        }
    }
}

void dfs_a(int u, int v) {
    if (u > 7 || v >= n) return;
    if (v) dfs_c(u, 0, v);
    
    for (int i = 1; i <= 9; ++i) {
        if (!used[i]) {
            used[i] = 1;
            dfs_a(u + 1, v * 10 + i);
            used[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs_a(0, 0);
    printf("%d", cnt);
}
