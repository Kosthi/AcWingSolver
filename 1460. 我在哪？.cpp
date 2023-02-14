#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 100;

int n;
string str;

bool check(int len) {
    unordered_set<string> set;
    for (int i = 0; i + len - 1 < str.size(); ++i) {
        auto s = str.substr(i, len);
        if (set.count(s)) return false;
        set.insert(s);
    }
    return true;
}

int main() {
    cin >> n >> str;
    
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    
    cout << r << endl;
}
