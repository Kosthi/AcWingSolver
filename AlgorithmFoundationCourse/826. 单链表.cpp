#include <cstdio>

const int N = 100010;

int n;
int head, e[N], ne[N], idx;
char op;
int a, b;

void init() {
    head = -1;
    idx = 0;
}

void add_to_head(int x) {
    e[idx] = x, ne[idx] = head, head = idx++;
}

void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

void del(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    init();
    scanf("%d", &n);
    while (n--) {
        scanf("\n%c", &op);
        if (op == 'H') {
            scanf("%d", &a);
            add_to_head(a);
        }
        else if (op == 'D') {
            scanf("%d", &a);
            if (a == 0) head = ne[head];
            else del(a - 1);
        }
        else {
            scanf("%d %d", &a, &b);
            add(a - 1, b);
        }
    }
    for (int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);
}
