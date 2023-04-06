#include <cstdio>
#include <iostream>

int n;

struct Paper {
    int h, w;
}paper[10];

int main() {
    paper[0].h = 1189, paper[0].w = 841;
    for (int i = 1; i < 10; ++i) {
        paper[i].h = paper[i - 1].h / 2;
        paper[i].w = paper[i - 1].w;
        if (paper[i].h < paper[i].w) std::swap(paper[i].h, paper[i].w);
    }
    scanf("A%d", &n);
    printf("%d\n%d\n", paper[n].h, paper[n].w);
}
