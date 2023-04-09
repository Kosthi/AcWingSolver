#include <iostream>
#include <algorithm>

using namespace std;

int n;

struct T {
    int l, r;
    bool operator<(const T& t) const {
        return l < t.l;
    }
};

int main() {
    cin >> n;
    T t[n];
    int h1, m1, s1;
    int h2, m2, s2;
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d:%d - %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        t[i].l = h1 * 3600 + m1 * 60 + s1;
        t[i].r = h2 * 3600 + m2 * 60 + s2;
    }
    sort(t, t + n);
    if (t[0].l != 0) {
        h1 = t[0].l / 3600;
        m1 = t[0].l / 60 % 60;
        s1 = t[0].l % 60;
        printf("00:00:00 - %02d:%02d:%02d\n", h1, m1, s1);
    }
    for (int i = 0; i < n - 1; ++i) {
        if (t[i].r != t[i + 1].l) {
            h1 = t[i].r / 3600;
            m1 = t[i].r / 60 % 60;
            s1 = t[i].r % 60;
            h2 = t[i + 1].l / 3600;
            m2 = t[i + 1].l / 60 % 60;
            s2 = t[i + 1].l % 60;
            printf("%02d:%02d:%02d - %02d:%02d:%02d\n", h1, m1, s1, h2, m2, s2);
        }
    }
    if (t[n - 1].r != 23 * 3600 + 59 * 60 + 59) {
        h1 = t[n - 1].r / 3600;
        m1 = t[n - 1].r / 60 % 60;
        s1 = t[n - 1].r % 60;
        printf("%02d:%02d:%02d - 23:59:59\n", h1, m1, s1);
    }
}
