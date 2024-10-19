
#include<stdio.h>

int main(){
    int m,n,i,t=0,k,round,max,min;
    scanf("%d%d%d",&m,&n,&k);
    k*=1000;
    round=n-m;
    //取最少
    while(t*n<k)++t;//取最大情况
    if(t*m<=k&&t*n>=k)max=t;//判断是否满足
    while(t*m<=k)++t;
    --t;
    if(t*m<=k&&t*n>=k)min=t;
    if(min!=0&&max!=0)printf("%d %d",max,min);
    else printf("UNSATISFIABLE");
    return 0;
}