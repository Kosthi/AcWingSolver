#include <cstring>
#include <iostream>

using namespace std;

const int N = 110;

int n, op;
string s, str;

int main() {
    cin >> s >> op >> n;
    int length = strlen(s.c_str());
    if (op == 0) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32; 
        }
    }
    while (n--) {
        cin >> str;
        if (op == 1) {
            for (int i = 0; i < str.size(); ++i) {
                string tmp = str.substr(i, length);
                if (tmp == s) {
                    cout << str << endl;
                    break;
                }
            }
        }
        else {
            string ss = str;
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32; 
            }
            for (int i = 0; i < str.size(); ++i) {
                string tmp = str.substr(i, length);
                if (tmp == s) {
                    cout << ss << endl;
                    break;
                }
            }
        }
    }
}
