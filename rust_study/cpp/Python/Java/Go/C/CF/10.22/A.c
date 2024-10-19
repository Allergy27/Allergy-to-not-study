#include<stdio.h>

int main(){
    int n,i,j;char ans[5];
    scanf("%d",&n);
    for(i=0;i<n;++i){
        int flag=1,res=0;
        scanf("%s",ans);
        for(j=0;j<4;++j){
            ++res;
            if(ans[j]=='0')ans[j]='0'+10;
            res+=(flag-ans[j]+'0')>0? (flag-ans[j]+'0'):(flag-ans[j]+'0')*(-1);
            flag=ans[j]-'0';
        }
        printf("%d\n",res);
    }
    //getchar();getchar();
    return 0;
}