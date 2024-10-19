#include<stdio.h>

int main(){
    int i,x,n;
    scanf("%d%d",&n,&x);
    int max=x,min=x,ans=x;
    for(i=1;i<n;++i){
        scanf("%d",&x);
        max=max<x? x:max;
        min=min>x? x:min;
        ans+=x;
    }
    printf("%d",(max+min)*(max-min+1)/2-ans);
    getchar();getchar();
    return 0;
}   