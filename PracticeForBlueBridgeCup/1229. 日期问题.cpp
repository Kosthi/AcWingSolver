#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int check_vaild_year(int year) {
    if (year < 60) return 2000;
    return 1900;
}

bool check_leap(int year) {
    year += check_vaild_year(year);
    return year % 100 && year % 4 == 0 || year % 400 == 0;
}

bool check_vaild_month(int month) {
    return month <= 12 && month >= 1;
}

bool check_vaild_day(int year, int month, int day) {
    if (month != 2) return months[month] >= day && day >= 1;
    return day <= months[month] + check_leap(year) && day >= 1;
}

void case1(int n, int m, int k) {
    if (check_vaild_month(m) && check_vaild_day(n, m, k)) {
        printf("%d-%02d-%02d\n", n + check_vaild_year(n), m, k);
    }
}

void case2(int n, int m, int k, int flag) {
    if (n > m) swap(n, m);
    if (check_vaild_month(n) && check_vaild_day(k, n, m)) {
        printf("%d-%02d-%02d\n", k + check_vaild_year(k), n, m);
    }
    if (flag) exit(0);
    if (n == m) return;
    if (check_vaild_month(m) && check_vaild_day(k, m, n)) {
        printf("%d-%02d-%02d\n", k + check_vaild_year(k), m, n);
    }
}

int main() {
    scanf("%d/%d/%d", &n, &m, &k);
    if (n < k) {
        case1(n, m, k);
        if (n == m && n == k) return 0;
        case2(n, m, k, 0);
    }
    else {
        case2(n, m, k, 0);
        if (n == m && n == k) return 0;
        case1(n, m, k);
    }
}
