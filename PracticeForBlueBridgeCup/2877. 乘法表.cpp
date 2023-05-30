#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int p;

string toHex(int n) {
    string ans;
    while (n) {
        int s = n % p;
        if (s >= 10) ans.push_back(s - 10 + 'A');
        else ans.push_back(s + '0');
        n /= p;
    }
    reverse(ans.begin(),  ans.end());
    return ans;
}

int main() {
    scanf("%d", &p);
    for (int i = 1; i < p; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (i >= 10 && j >= 10) printf("%c*%c=%s ", i - 10 + 'A', j - 10 + 'A', toHex(i * j).c_str());
            else if (j >= 10) printf("%d*%c=%s ", i, j - 10 + 'A', toHex(i * j).c_str());
            else if (i >= 10) printf("%c*%d=%s ", i - 10 + 'A', j, toHex(i * j).c_str());
            else printf("%d*%d=%s ", i, j, toHex(i * j).c_str());
        }
        puts("");
    }
}
