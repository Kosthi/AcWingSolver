#include <iostream>
#include <sstream>
#include <map>

#define x first
#define y second

using namespace std;

const int N = 100;

string s, tp;
int h[N];
int k;

map<char, string> mp;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i + 1] == ':') h[s[i++] - 'a'] = 2;
        else h[s[i] - 'a'] = 1;
    }
    cin >> k;
    getchar();
    for (int i = 1; i <= k; ++i) {
        getline(cin, s);
        stringstream ssin(s);
        mp.clear();
        ssin >> s;
        while (ssin >> s && h[s[1] - 'a'] && s[0] == '-' && s.size() == 2) {
            if (h[s[1] - 'a'] == 1) mp[s[1]] = "$";
            else if (h[s[1] - 'a'] == 2) {
                ssin >> tp;
                if (!tp.empty()) mp[s[1]] = tp;
                tp.clear();
            }
        }
        printf("Case %d:", i);
        for (auto it: mp) {
            if (it.y == "$") printf(" -%c", it.x);
            else printf(" -%c %s", it.x, it.y.c_str());
        }
        puts("");
    }
}
