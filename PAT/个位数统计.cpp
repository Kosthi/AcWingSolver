#include <iostream>
#include <cstring>

using namespace std;

string s;
int h[10];

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); ++i) h[s[i] - '0']++;
    for (int i = 0; i < 10; ++i)
        if (h[i]) printf("%d:%d\n", i, h[i]);
}
