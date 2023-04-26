#include <iostream>

using namespace std;

const int N = 110; 

int n;
int a, b, c, d;
int st[N][N];
int cnt;

int main() {
    cin >> n;
    while (n--) {
        cin >> a >> b >> c >> d;
        for (int i = a; i < c; ++i)
            for (int j = b; j < d; ++j) 
                st[i][j] = 1;
    }
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (st[i][j]) cnt++;
    cout << cnt << endl;
}
