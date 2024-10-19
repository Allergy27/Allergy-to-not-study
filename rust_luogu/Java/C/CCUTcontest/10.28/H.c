#include<stdio.h>

int main(){
    int t,n,i,j,k,p;
    scanf("%d",&t);
    for(i=0;i<t;++i){
        int ans[100]={0};
        scanf("%d",&n);
        for(j=0;j<n;++j){
            scanf("%d",&k);
            ++ans[k];
        }
        p=ans[0];
        int all=p;
        for(j=1;j<100;++j){
            k=ans[j];
            if(k<=p)all+=k;
            else {
                printf("NO\n");
                break;
            }
            if(all==n){
                printf("YES\n");
                break;
            }
            p=k;
        }
    }
    getchar();getchar();
    return 0;
}