#include<stdio.h>

int main(){
    int lenth,width;
    printf("请输入长和宽:");
    scanf("%d %d",&lenth,&width);
    printf("面积：%d，周长：%d",lenth*width,(lenth+width)*2);
    getchar();getchar();
    return 0;
}