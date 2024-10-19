#include<stdio.h>

int main(){
    int n,ans[2]={0,0};scanf("%d",&n);
    for(int i=1;i<=n;++i)if(n%i==0)++ans[i%2];
    printf("%s",ans[0]==ans[1]? "yes":"no");
    getchar();getchar();
    return 0;
}