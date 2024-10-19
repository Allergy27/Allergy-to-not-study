#include<stdio.h>

int main(){
    double Fa,Ma;int XorY;
    printf("您的性别是(男:1 女:0):");
    scanf("%d",&XorY);
    printf("请输入父母的身高(用' '隔开)");
    scanf("%lf %lf",&Fa,&Ma);
    printf("%lf",XorY? (Fa*0.923+Ma)/2:(Fa+Ma)*1.08/2);
    getchar();getchar();
    return 0;
}