#include <iostream>

using namespace std;

typedef long long LL;

LL n;

int main() {
    cin >> n;
    n /= 1000;
    int h = n / 60 / 60 % 24;
    int m = n / 60 % 60;
    int s = n % 60;
    printf("%02d:%02d:%02d", h, m, s);
}
