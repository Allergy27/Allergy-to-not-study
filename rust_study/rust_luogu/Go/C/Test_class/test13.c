#include<stdio.h>

int main(){
    int m,n,r=0;
    printf("请输入行数m:");
    scanf("%d",&m);
    printf("请输入要输出的星星数n:");
    scanf("%d",&n);
    while(m--){
        int t=r++;
        while(t--)printf(" ");
        int k=n;
        while(k--)printf("*");
        printf("\n");
    }
    getchar();getchar();
    return 0;
}