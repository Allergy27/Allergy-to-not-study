#include<stdio.h>

int main(){
    int n,l,i,j,t,ans=0,flag=0,rr=0,pp=0;
    scanf("%d%d",&n,&l);
    for(i=0;i<n;++i){//执行
        scanf("%d",&t);
        if(flag==0){ans+=t==2? 3:2;
            if(ans<l)++pp;
            else{
                --ans;flag=1;
                if((ans>l)){
                    printf("No");
                    rr=1;
                    break;
                }
            }
        }
        else{
            if(t==1&&pp>=0)--pp;
            else{
                printf("No");
                rr=1;
                break;
            }
        }
    }
    if(rr==0)printf("Yes");
    getchar();getchar();
    return 0;
}