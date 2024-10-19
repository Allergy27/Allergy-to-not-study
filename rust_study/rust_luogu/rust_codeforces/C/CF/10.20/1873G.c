#include<stdio.h>

int main(){
    int n,flag=2,ans=0,count=0,i,j=0;scanf("%d",&n);
    for(i=0;i<n;++i){
        int ans=0;
        char str[200000]={0};
        scanf("%s",str);
        //A->B
        //flag=str[0]=='A'? 1:0;
        while(str[j]!=0){
            if(str[j]=='A'){
                ++count;
                ans+=flag==1? 1:0;
            }
            else if(str[j]=='B'&&flag==0){
                ans+=count;count=0;
                flag=2;
            }
            else if(str[j]=='B'&&flag==2){
                flag=1;

            }
            ++j;
        }
        printf("%d\n",ans);
    }
    getchar();getchar();
    return 0;
}