#include<stdio.h>

int main(){
    int x,y,z;
    printf("请输入三个整数(' '分隔)");
    scanf("%d%d%d",&x,&y,&z);
    printf("和:%d 乘积:%d 平均数:%.2lf",x+y+z,x*y*z,(x+y+z)/3.0);

    getchar();getchar();
    return 0;
}