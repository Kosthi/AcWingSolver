// 模拟
#include <iostream>

using namespace std;

int n;


int main() {
    cin >> n;
    int gai = n;
    while (gai >= 3) {
        n += gai / 3;
        gai = gai / 3 + gai % 3;
    }
    cout << n << endl;
}
