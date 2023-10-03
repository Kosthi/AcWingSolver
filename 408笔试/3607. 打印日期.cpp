#include <cstdio>

int y, d, leap;
int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    while (scanf("%d %d", &y, &d) != EOF) {
        leap = 0;
        if (y % 400 == 0 || y % 4 == 0 && y % 100) leap = 1;
        
        int i = 0;
        while (d > 0) {
            if (months[i] >= d) {
                printf("%04d-%02d-%02d\n", y, i + 1, d);
                break;
            }
            else if (months[i] < d) {
                if (i == 1) d -= leap;
                d -= months[i];
            }
            ++i;
        }
        if (!d) printf("%04d-%02d-%02d\n", y, i, i == 2 ? months[i - 1] + leap : months[i - 1]);
    }
}
