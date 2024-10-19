#include<stdio.h>

int main(){
    int score;
    printf("请输入成绩:");
    scanf("%d",&score);
    score=score/10==10?9:score/10;
    if(score<6||score>10)printf("E");
    else printf("%c",65+9-score);
    getchar();getchar();
    return 0;
}