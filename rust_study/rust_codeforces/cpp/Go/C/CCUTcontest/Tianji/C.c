#include<stdio.h>

int main(){
    int m,n,i,j,ans;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        int res=0;
        scanf("%d",&m);
        for(j=0;j<m;++j)scanf("%d",&ans);
        res+=6*(10-m)*(9-m)/2;//求组合数并*6
        printf("%d\n",res);
    }
    //getchar();getchar();
    return 0;
}