#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    if (c < a && d < a) {
        printf("%d-N %d-N\n", c, d);
        printf("zhang da zai lai ba\n");
    }
    else if (c >= a && d >= a) {
        printf("%d-Y %d-Y\n", c, d);
        printf("huan ying ru guan\n");
    }
    else if (d < a && c >= b) {
        printf("%d-Y %d-Y\n", c, d);
        printf("qing %d zhao gu hao %d\n", 1, 2);
    }
    else if (c < a && d >= b) {
        printf("%d-Y %d-Y\n", c, d);
        printf("qing %d zhao gu hao %d\n", 2, 1);
    }
    else if (c < a && d >= a) {
        printf("%d-N %d-Y\n", c, d);
        printf("2: huan ying ru guan\n");
    }
    else if (d < a && c >= a) {
        printf("%d-Y %d-N\n", c, d);
        printf("1: huan ying ru guan\n");
    }
}
