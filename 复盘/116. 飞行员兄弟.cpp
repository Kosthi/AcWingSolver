#include <iostream>

using namespace std;

char a[5][5];
int st[5][5];


void turn(int i, int j) {
    // a[i][j] = a[i][j] == '+' ? '-' : '+';
    for (int k = 0; k < 4; ++k) {
        st[k][j]++;
        st[i][k]++;
    }
    st[i][j]--;
}

int main() {
    for (int i = 0; i < 4; ++i) scanf("%s", a[i]);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (a[i][j] == '+') turn(i, j);
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (st[i][j] % 2) cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (st[i][j] % 2) cout << i + 1 << " " << j + 1 << endl;
        }
    }
}
