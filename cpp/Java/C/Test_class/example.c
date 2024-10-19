#include<stdio.h>

typedef struct stuInfo {
    char Num[10];
    char Name[10];
    float Eng, Math, Chin;
}stu;

int main() {
    stu qwq[5];
    float sum[5];
    for(int i = 0;i < 5;++i) {
        gets(qwq[i].Num);
        gets(qwq[i].Name);
        scanf("%f%f%f", &qwq[i].Eng, &qwq[i].Math, &qwq[i].Chin);
        fflush(stdin); //我们需要加上这个来帮助scanf读掉缓存区的的\n
        sum[i] = qwq[i].Eng + qwq[i].Math + qwq[i].Chin;
    }
    for(int i = 0;i < 5;++i)printf("%f\t", sum[i]);
    getchar();getchar();
    return 0;
}
/*
20230001
Gnius1
100 100 100
20230002
Gnius2
100 100 99
20230003
Gnius3
100 100 98
20230004
Gnius4
100 100 97
20230005
Gnius5
100 100 96

*/