#include<stdio.h>

int main(){
    int a,u,x,n,m;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int all[4]={a,a,2*a};
    if(x<4)printf("%d",all[x-1]);
    else if(x==n-1)printf("%d",m);
    else{
        int qvq[2]={0,1};
        int ans[2]={2,0};
        int target[2]={2,0};
        for(int i=3;i<n-1;++i){
            if(i==x){
                target[0]=ans[0];target[1]=ans[1];
            }
            ans[0]+=qvq[0];ans[1]+=qvq[1];
            qvq[1]=qvq[1]+qvq[0];qvq[0]=qvq[1]-qvq[0];
        }
        printf("%d",((ans[1]*target[0]-target[1]*ans[0])*a+target[1]*m)/ans[1]);
    }
    getchar();getchar();
    return 0;
}