#include <cstring>
#include <iostream>

using namespace std;

const int N = 100;

int n;
string str;

int main() {
    cin >> n >> str;
    int sum = 0;
    for (int i = 0, j; i < n; ++i) {
        if (str[i] == 'x') {
            j = i + 1;
            while (j < n && str[j] == 'x') j++;
            sum += max(0, j - i - 2);
            i = j;      
        }
    }
    printf("%d", sum);
}
