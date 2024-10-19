#include<stdio.h>

int main(){
    int n,i,first,rest;
    scanf("%d",&n);//总共有多少数据
    scanf("%d",&first);//存放第一个数据
    for(i=1;i<n;++i){
        scanf("%d",&rest);//存放剩余的数据
        if(rest != first){//判断剩下的与第一个是否相等
            printf("No");
            return 0;//直接退出,避免多输出一个Yes
        }
    }
    printf("Yes");
    return 0;
}