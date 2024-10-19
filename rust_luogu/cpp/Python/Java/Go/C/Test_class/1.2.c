#include<stdio.h>

int main(){
    int x,y,z;
    printf("请输入两个整数：");
    scanf("%f%d",&x,&y);
    z=x+y;
    printf("这两个整数的和是%d\n",z);
    getchar();getchar();
    return 0;
}