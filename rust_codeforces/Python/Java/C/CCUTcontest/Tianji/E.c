#include<stdio.h>

int main(){
    int n,m,i,j;
    while (scanf("%d",&n)!=EOF){
        int len=0,ans[12];
        while(n!=0){
            ans[len]=n%2;
            n/=2;
            ++len;
        }
        --len;
        for(;len>=0;--len)printf("%d",ans[len]);
        printf("\n");
    }
    //getchar();getchar();
    return 0;
}