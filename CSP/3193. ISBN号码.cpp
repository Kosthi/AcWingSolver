#include <cstdio>

const int N = 20;

char s[20];
int sum, cnt = 1;

int main() {
    scanf("%s", s);
    sum += (s[0] - '0') * cnt++;
    for (int i = 2; i < 5; ++i) {
        sum += (s[i] - '0') * cnt++;
    }
    for (int i = 6; i < 11; ++i) {
        sum += (s[i] - '0') * cnt++;
    }
    if (sum % 11 == 10 && s[12] == 'X' || sum % 11 == s[12] - '0') puts("Right");
    else {
        for (int i = 0; i < 12; ++i) printf("%c", s[i]);
        if (sum % 11 == 10) printf("X");
        else printf("%d", sum % 11);
    }
}
