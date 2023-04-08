#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

string str;

int main() {
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i + 1] >= '0' && str[i + 1] <= '9') {
            for (int j = 0; j < str[i + 1] - '0'; ++j) {
                printf("%c", str[i]);
            }
            i++;
        }
        else printf("%c", str[i]);
    }
}
