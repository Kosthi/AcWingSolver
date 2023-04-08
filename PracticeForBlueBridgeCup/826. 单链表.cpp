#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;

int m;
char op;
int head, e[N], ne[N], idx; 

void init() {
    head = -1;
    idx = 0;
}

void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}

void insert(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

int main() {
    scanf("%d", &m);
    init();
    for (int i = 0; i < m; ++i) {
        cin >> op;
        if (op == 'H') {
            int x;
            scanf("%d", &x);
            add_to_head(x);
        }
        else if (op == 'D') {
            int k;
            scanf("%d", &k);
            if (!k) head = ne[head];
            else remove(k - 1);
        }
        else {
            int k, x;
            scanf("%d %d", &k, &x);
            insert(k - 1, x);
        }
    }
    
    for (int i = head; i != -1; i = ne[i])
        printf("%d ", e[i]);
}
