#include<stdio.h>

int main(){
    int n,i,j,abs(int);char ans[5];
    scanf("%d",&n);
    for(i=0;i<n;++i){
        int flag=1,res=0;
        scanf("%s",ans);
        for(j=0;j<4;++j){
            ans[j]=ans[j]=='0'? ans[j]+10:ans[j];
            res+=abs(ans[j]-1-'0');
        }
        printf("%d\n",res);
    }
    //getchar();getchar();
    return 0;
}

int abs(int k){
    return k<0? -1*k:k;
}