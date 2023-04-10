#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

string s;
LL p, pa, pat;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'P') p++;
        else if (s[i] == 'A') pa += p;
        else pat += pa;
    }
    cout << pat % 1000000007 << endl;
}
