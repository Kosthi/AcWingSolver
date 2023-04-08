#include <iostream>
#include <cstring>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    int s = (m - n + 50) / 100;
    int h = s / 60 / 60;
    int m = s % 3600 / 60;
    int ss = s % 60;
    printf("%02d:%02d:%02d", h, m, ss);
}
