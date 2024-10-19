#include<stdio.h>

typedef struct student {
    int num;
    double score;
}st;



int main() {
    st qwq[11];
    for(int i = 0;i < 10;++i)scanf("%d%lf", &qwq[i].num, &qwq[i].score);
    for(int i = 0;i < 10;++i)
        for(int j = i;j > 0;--j) {
            st tmp;
            if(qwq[j].score < qwq[j - 1].score) {
                tmp = qwq[j];
                qwq[j] = qwq[j - 1];
                qwq[j - 1] = tmp;
            }
        }

    for(int i = 0;i < 10;++i)printf("%d %.1lf\n", qwq[i].num, qwq[i].score);
    getchar();getchar();
    return 0;
}