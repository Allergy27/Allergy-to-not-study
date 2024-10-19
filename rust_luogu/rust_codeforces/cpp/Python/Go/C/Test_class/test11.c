#include<stdio.h>

int main(){
    int a,b,c;
    printf("请输入三个整数：");
    scanf("%d%d%d",&a,&b,&c);
    printf("%d %d %d",(a>b?a:b)>c?(a>b?a:b):c,a+b+c-(a>b?a:b)>c?(a>b?a:b):c-(a<b?a:b)<c?(a<b?a:b):c,(a<b?a:b)<c?(a<b?a:b):c);
    getchar();getchar();
    return 0;
}