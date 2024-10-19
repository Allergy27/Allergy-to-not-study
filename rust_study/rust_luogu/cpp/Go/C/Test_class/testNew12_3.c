#include<stdio.h>

typedef struct score{
    char num[11];
    double goal;
}sc;



int main() {
    int n;
    scanf("%d", &n);
    sc qwq[501];
    for(int i = 0;i < n;++i)scanf("%s%lf", qwq[i].num, &qwq[i].goal);
    for(int i = 0;i < 10;++i)
        for(int j = i;j > 0;--j) {
            sc tmp;
            if(qwq[j].goal > qwq[j - 1].goal) {
                tmp = qwq[j];
                qwq[j] = qwq[j - 1];
                qwq[j - 1] = tmp;
            }
        }
    for(int i = 0;i < n;++i)printf("%s\n", qwq[i].num);
    getchar();getchar();
    return 0;
}