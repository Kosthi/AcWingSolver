#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int T;
string line;

int get_time() {
    string line;
    getline(cin, line);
    if (line.back() != ')') line += " (+0)";
    int h1, m1, s1, h2, m2, s2, d;
    sscanf(line.c_str(), "%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d);
    return (h2 * 3600 + m2 * 60 + s2) - (h1 * 3600 + m1 * 60 + s1) + d * 24 * 3600;
}

int main() {
    scanf("%d", &T);
    getline(cin, line);
    while (T--) {
        int time = (get_time() + get_time()) / 2;
        int h = time / 3600;
        int m = time % 3600 / 60;
        int s = time % 60;
        printf("%02d:%02d:%02d\n", h, m, s);
    }
}
