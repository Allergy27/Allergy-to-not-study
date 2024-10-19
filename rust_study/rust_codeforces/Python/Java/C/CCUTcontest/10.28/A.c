#include<stdio.h>

int main(){
    int i,m,j,n,ans[1001],t=0,flag=-1;
    scanf("%d",&n);
    for(i=0;i<n;++i)
        scanf("%d",&ans[i]);
    if(n==1){printf("%d %d",0,0);return 0;}
    while(flag==-1){
        for(j=1;j<n;++j){
            if(t>1000){
                printf("%d",-1);return 0;
            }
            if((j-1+ans[j-1]*t)%n!=(j+ans[j]*t)%n){
                ++t;flag=-1;break;
            }
            flag=(j+ans[j]*t)%n;
        }
    }
    
    printf("%d %d",t,flag);    
    getchar();getchar();
    return 0;
}