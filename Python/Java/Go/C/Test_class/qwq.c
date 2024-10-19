#include <stdio.h>
int main(){
    int flag=0; int i, x;
    printf("请输入10个整数：");
    for(i=1;i<=10;i++){
        scanf("%d", &x); 
        if (x<0) {
            flag=1;
            break;
        }
    }
    if (flag==1) printf("输入的整数中有负数\n"); 
    else printf("输入的整数中没有负数\n");
    return 0;
}