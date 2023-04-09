#include <iostream>

using namespace std;

int n;
int org[10][6], st[6][6];

int main() {
    for (int i = 0; i < 6; ++i) {
        cin >> org[0][i];
        st[i][org[0][i] - 1] = 1;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j)
            for (int k = 5; k >= 0; --k) {
                if (!st[j][k]) {
                    org[i + 1][j] = k + 1;
                    st[j][k] = 1;
                    break;
                }
            }
    }
    for (int i = 0; i < 5; ++i)
        cout << org[n][i] << " ";
    cout << org[n][5];
}
