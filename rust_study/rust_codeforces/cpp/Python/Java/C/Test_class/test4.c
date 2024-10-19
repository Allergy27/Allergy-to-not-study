#include<stdio.h>

int main(){
    char small;
    printf("请输入一个小写字母：");
    scanf("%c",&small);
    printf("它的大写是:%c",small-32);
    getchar();getchar();
    return 0;
}