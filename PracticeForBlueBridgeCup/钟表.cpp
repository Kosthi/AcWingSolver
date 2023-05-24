#include <iostream>
#include <cmath>

using namespace std;

double hw = 1.0 / 120, mw = 0.1, sw = 6.0;

int main()
{
    for (int s = 0; s <= 6; ++s) {
        for (int f = 0; f < 60; ++f) {
            for (int m = 0; m < 60; ++m) {
                if (s == 0 && f == 0 && m == 0) continue;
                double second = s * 3600 + f * 60 + m;
                double x = fabs(second * hw - second * mw);
                double y = fabs(second * mw - second * sw);
                while (x > 360) x -= 360;
                while (y > 360) y -= 360;
                if (x == 2 * y)
                    cout << s << " " << f << " " << m << endl;
            }
        }
    }
    return 0;
}
