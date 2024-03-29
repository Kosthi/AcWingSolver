#include <iostream>
#include <algorithm>

using namespace std;

string s1, s2, s3, s4;
int cnt;
string days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    cin >> s1 >> s2 >> s3 >> s4;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G' && !cnt) {
            int day = s1[i] - 'A';
            cout << days[day] << " ";
            cnt++;
        }
        else if (cnt == 1 && s1[i] == s2[i] && (s1[i] >= 'A' && s1[i] <= 'N' || s1[i] >= '0' && s1[i] <= '9')) {
            if (s1[i] >= 'A' && s1[i] <= 'N') printf("%02d:", s1[i] - 'A' + 10);
            else printf("%02d:", s1[i] - '0');
            break;
        }
    }
    for (int i = 0; i < s3.size(); ++i) {
        if (s3[i] == s4[i] && (s3[i] >= 'A' && s3[i] <= 'Z' || s3[i] >= 'a' && s3[i] <= 'z')) {
            printf("%02d\n", i);
            break;
        }
    }
}
