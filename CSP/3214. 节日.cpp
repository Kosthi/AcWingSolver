#include <cstdio>

const int N = 2100;

int a, b, c, y[2];
int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int map[N][20][40];

bool is_leap(int year) {
    return year % 400 == 0 || year % 4 == 0 && year % 100;
}

int main() {
    scanf("%d %d %d %d %d", &a, &b, &c, &y[0], &y[1]);
    
    int base = 1;
    for (int y = 1850; y <= 2050; ++y) {
        for (int m = 1; m <= 12; ++m) {
            int sub = m == 2 ? is_leap(y) : 0;
            for (int d = 1; d <= months[m - 1] + sub; ++d) {
                base = base % 7 + 1;
                map[y][m][d] = base;
            }
        }
    }

    for (int i = y[0]; i <= y[1]; ++i) {
        int t = 0;
        int sub = a == 2 ? is_leap(i) : 0;
        int d;
        for (d = 1; d <= months[a - 1] + sub; ++d) {
            if (map[i][a][d] == c) t++;
            if (t == b) {
                printf("%d/%02d/%02d\n", i, a, d);
                break;
            }
        }
        if (d > months[a - 1] + sub) puts("none");
    }
}
