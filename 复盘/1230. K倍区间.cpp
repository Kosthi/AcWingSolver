#include <cstdio>

const int N = 100010;

typedef long long LL;

int n, k;
LL s[N], cnt[N];
LL res;

int main() {
    scanf("%d %d", &n, &k);
    // 关于预先处理cnt[0]=1我的理解，因为对k取余==0的前缀和即说明本身就是k的倍数，比如取余结果是0的有3个
    // 假设k=2，那三个数是4，6，8，如果不预处理cnt[0]=1，那么cnt[0]=3，但你不能说k倍区间有C3取2=3
    // 显然不止，4，6，8本身也是一个k倍区间，所以应该是6个，所以预处理cnt[0]=1，结果就是cnt[0]=4
    // 即C4取2=6
    // 只有0有这种特殊情况
    cnt[0] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &s[i]);
        s[i] = (s[i - 1] + s[i]) % k;
        /// res += cnt[s[i]];
        cnt[s[i]]++;
    }
    for (int i = 0; i < k; ++i)
        res += cnt[i] * (cnt[i] - 1) / 2;
    printf("%lld", res);
}
