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
