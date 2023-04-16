#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
    cin >> s;
    if (s.size() == 4) {
        int y = (s[0] - '0') * 10 + s[1] - '0';
        if (y < 22) {
            printf("%d-%02d", 2000 + y, (s[2] - '0') * 10 + s[3] - '0');
        }
        else {
            printf("%d-%02d", 1900 + y, (s[2] - '0') * 10 + s[3] - '0');
        }
    }
    else {
        int y = 0;
        for (int i = 0; i < 4; ++i) {
            y = y * 10 + s[i] - '0';
        }
        printf("%d-%02d", y, (s[4] - '0') * 10 + s[5] - '0');
    }
}
