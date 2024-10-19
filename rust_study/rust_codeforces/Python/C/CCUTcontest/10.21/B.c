#include<stdio.h>

int main(){
    int n,target;
    scanf("%d",&n);//骰子数
    scanf("%d",&target);
    if(target >=n && target <= 6*n)printf("Yes");//骰子数<=p<=6*骰子数
    else printf("No");
    return 0;
}