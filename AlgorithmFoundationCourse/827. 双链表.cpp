#include <cstdio>

const int N = 100010;

int e[N], l[N], r[N], idx;

int n;
char op[2];
int a, b;
int k, x;

void init() {
    r[0] = 1, l[1] = 0;
    idx = 2;
}

void add(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void del(int k) {
    r[l[k]] = r[k], l[r[k]] = l[k];
}

int main() {
    init();
    scanf("%d", &n);
    while (n--) {
        scanf("%s", &op);
        if (op[0] == 'L') {
            scanf("%d", &x);
            add(0, x);
        }
        else if (op[0] == 'R') {
            scanf("%d", &x);
            add(l[1], x);
        }
        else if (op[0] == 'D') {
            scanf("%d", &k);
            del(k + 1);
        }
        else if (op[1] == 'L') {
            scanf("%d %d", &k, &x);
            add(l[k + 1], x);
        }
        else if (op[1] == 'R') {
            scanf("%d %d", &k, &x);
            add(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i]) printf("%d ", e[i]);
}
