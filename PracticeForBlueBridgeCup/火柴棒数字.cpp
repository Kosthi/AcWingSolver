// dp bag
#include <iostream>

using namespace std;

const int N = 310;

string dp[N];
int nums[] = {6,2,5,5,4,5,6,3,7,6};

bool check(string& s) {
    int st[10] = {0};
    for (auto c : s) {
        if (st[c - '0'] < 10) st[c - '0']++;
        else return false;
    }
    return true;
}

bool judge(string& s1, string& s2) {
    if (s1.size() == s2.size()) return s1 > s2;
    return s1.size() > s2.size();
}

bool cmp(int a, int b) {
    return a > b;
}

void conver(string& s) {
    int n[s.size()];
    for (int i = 0; i < s.size(); ++i) n[i] = s[i] - '0';
    sort(n, n + s.size(), cmp);
    for (int i = 0; i < s.size(); ++i) s[i] = n[i] + '0';
}

int main() {
    for (int i = 1; i <= N - 1; ++i) {
        string tp;
        for (int t = 9; ~t; --t) {
            if (i - nums[t] >= 0) {
                string tmp = dp[i - nums[t]];
                tmp.push_back(t + '0');
                conver(tmp);
                if (judge(tmp, tp) && check(tmp)) tp = tmp;
            }
        }
        dp[i] = tp;
    }
    cout << dp[300];
}

// greedy
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 300;

string s;

int main()
{
  int n = N;
  for (int i = 0; i < 10; ++i) s += '9';
  n -= 6 * 10;
  // for (int i = 0; i < 10; ++i) s += '8';
  // n -= 7 * 10;
  for (int i = 0; i < 10; ++i) s += '7';
  n -= 3 * 10;
  // for (int i = 0; i < 10; ++i) s += '6';
  // n -= 6 * 10;
  for (int i = 0; i < 10; ++i) s += '5';
  n -= 5 * 10;
  for (int i = 0; i < 10; ++i) s += '4';
  n -= 4 * 10;
  for (int i = 0; i < 10; ++i) s += '3';
  n -= 5 * 10;
  for (int i = 0; i < 10; ++i) s += '2';
  n -= 5 * 10;
  for (int i = 0; i < 10 && n > 0; ++i, n -= 2) s += '1';
  printf("%s", s.c_str());
  return 0;
}
