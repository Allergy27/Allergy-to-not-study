#include<stdio.h>

int main(){
    int n,i,j,k,ans[9]={0};
    scanf("%d",&n);
    for(i=0;i<n;++i){
        int maxres=1,l;
        scanf("%d",&l);
        for(j=0;j<l;++j)scanf("%d",&ans[j]);
        for(j=0;j<l;++j){
            ++ans[j];
            int res=1;
            for(k=0;k<l;++k)res*=ans[k];
            maxres=res>maxres? res:maxres;
            --ans[j];
        }
        printf("%d\n",maxres);
    }
    getchar();getchar();
    return 0;
}