#include <cstdio>
#include <cmath>

typedef long long LL;

LL n, res = 1;

// 分解质因数
// n = p1_k1 * p2_k2 * p3_k3 * ...
// 结果为所有ki为奇数的乘积
int main() {
    scanf("%lld", &n);
    for (LL i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) s++, n /= i;
            if (s % 2) res *= i;
        }
    }
    // 剩下一个奇个数因子
    res *= n;
    printf("%lld", res);
}
