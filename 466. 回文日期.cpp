#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int cnt;
int date1, date2;

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


bool check_vaild(int date) {
    int year = date / 1e4;
    int month = date / 1e2 - year * 100;
    int day = date % 100;
    if (month > 12) return false;
    if (month != 2 && months[month] < day) return false;
    int leap = year % 100 && year % 4 == 0 || year % 400 == 0;
    if (day > 28 + leap && month == 2) return false;
    return true;
}

int main() {
    cin >> date1 >> date2;
    int dl = date1 / 1e4;
    int dr = date2 / 1e4;
    for (int i = dl; i <= dr; ++i) {
        int k = i, date = i;
        for (int i = 0; i < 4; ++i) {
            date = date * 10 + k % 10; k /= 10;
        }
        if (check_vaild(date) && date1 <= date && date <= date2) cnt++;
    }
    cout << cnt << endl;
}
