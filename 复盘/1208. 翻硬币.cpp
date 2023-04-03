#include <iostream>
#include <string>

using namespace std;

int cnt;
string s1, s2;

void turn(int i) {
    cnt++;
    s1[i] = s1[i] == 'o' ? '*' : 'o';
    s1[i + 1] = s1[i + 1] == 'o' ? '*' : 'o';
}

int main() {
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size() - 1; ++i) {
        if (s1[i] != s2[i]) turn(i);
    }
    cout << cnt << endl;
}
