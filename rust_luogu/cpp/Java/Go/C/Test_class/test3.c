#include<stdio.h>

int main(){
    int n,ans[100],i=0;
    printf("请输入数字(<2^10):");
    scanf("%d",&n);
    if(n==0){
        printf("0");
        getchar();getchar();
        return 0;
    }

    while(n>0){
        ans[i++]=n%10;
        n/=10;
    }
    while(i--)printf("%d",ans[n++]);
    getchar();getchar();
    return 0;
}