#include<stdio.h>
int main(){
    double D1,C,D,fee[9]={0},dis[9]={0},Cost=0,rest;int i,j,k=0,N,flag=0,next,gas;
    scanf("%lf%lf%lf%lf%d",&D1,&C,&D,&fee[0],&N);//读取输入
    for(i=1;i<=N;++i)scanf("%lf%lf",&dis[i],&fee[i]);//初始化数组
    dis[N+1]=D1;
    Cost=C*fee[0];//灌满油
    while(!flag){
        next=k+1;
        gas=k+1;
        if(k==0)for(i=0;i<=N;++i)if(dis[i]+C*D<dis[i+1])flag=1;//没找到下一个
        if(k==N+1&&!flag)break;//到终点或者到不了下一个点
        if(!flag){
            while(dis[gas]<=dis[k]+C*D){//找下一站
                if(fee[gas]<fee[k]){//当找到的值比k还小的时候
                    next=gas;
                    break;
                }
                next=fee[gas]<fee[next]? gas:next;//找到次小值
                if(gas<N+1)gas++;
                else break;
            }//找其中油费最低的
            rest=(dis[next]-dis[k])/D;
            if(fee[next]<fee[k])Cost+=C*(fee[next]-fee[k])+rest*fee[k];//比当前还低，退钱
            else Cost+=rest*fee[next];//补满
        }
        k=next;
    }
    if(flag)printf("No Solution");
    else printf("%.2lf",Cost);
    getchar();getchar();
    return 0;
}