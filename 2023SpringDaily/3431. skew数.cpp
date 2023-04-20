#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

string s;

int main() {
    while (cin >> s) {
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            sum += (s[i] - '0') * (pow(2, s.size() - i) - 1);
        }
        printf("%d\n", sum);
    }
}
