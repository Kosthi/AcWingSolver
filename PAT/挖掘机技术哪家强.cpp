#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int h[N];

int main() {
    cin >> n;
    int id, s, maxx = 0, maxi;
    for (int i = 0; i < n; ++i) {
        cin >> id >> s;
        h[id] += s;
    }
    for (int i = 0; i < N; ++i) {
        if (h[i] > maxx) {
            maxx = h[i];
            maxi = i;
        }
    }
    cout << maxi << " " << maxx << endl;
}
