#include<stdio.h>
int qwq[52][52];
int main(){
    int n,m,i,j,t,r,ans=0;
    scanf("%d%d",&n,&m);
    if(n==2){printf("%d",0);return 0;}
    for(i=0;i<m;++i){
        scanf("%d",&t);--t;
        for(j=1;j<n;++j){
            scanf("%d",&r);--r;
            qwq[r][t]=1;qwq[t][r]=1;
            t=r;
        }
    }
    for(i=0;i<n;++i)
        for(j=i+1;j<n;++j)
            ans+=qwq[i][j]==1? 0:1;
    printf("%d",ans);
    getchar();getchar();
    return 0;
}