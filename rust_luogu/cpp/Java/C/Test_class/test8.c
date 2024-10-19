#include<stdio.h>

int main(){
    int year;
    printf("请输入一个年份:");
    scanf("%d",&year);
    if(year%4==0&&year%100!=0||year%400==0)printf("是闰年");
    else printf("不是闰年");
    getchar();getchar();
    return 0;
}