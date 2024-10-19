#include<stdio.h>

int main() {
    int k;
    printf("请输入要输出的星星数k:");
    scanf("%d", &k);
    while(k--)printf("*");
    getchar();getchar();
    return 0;
}