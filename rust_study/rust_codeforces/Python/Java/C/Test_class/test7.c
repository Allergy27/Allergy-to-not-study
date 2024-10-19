#include<stdio.h>
#include<math.h>
int main(){
    printf("请输入一元二次方程ax^2+bx+c中的a,b,c:");
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    double derta=b*b-4*a*c;
    if(derta<0)printf("无解");
    else if(derta==0)printf("%d",-1*b/(2*a*c));
    else printf("两根分别为:%.2lf %.2lf",(-1*b+sqrt(derta))/(2*a*c),(-1*b-sqrt(derta))/(2*a*c));
    getchar();getchar();
    return 0;
}