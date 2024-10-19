#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct student {
    int num;
    double score;
}st;

int main() {
    srand(time(NULL));
    st qwq[11];
    st Max = { 0, 0 };
    // for(int i = 0;i < 10;++i)printf("%d %d%s\n", 1000 + i, rand() % 50+100,rand()%2-1?".0":".5");
    for(int i = 0;i < 10;++i)scanf("%d%lf", &qwq[i].num, &qwq[i].score);
    for(int i = 0;i < 10;++i)if(qwq[i].score > Max.score)Max = qwq[i];
    printf("%d %.1lf", Max.num, Max.score);
    getchar();getchar();
    return 0;
}