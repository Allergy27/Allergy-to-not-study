#include<stdio.h>
int main(){
    double D1,C,D,fee[9]={0},dis[9]={0},Cost=0,rest;int i,j,k=0,N,flag=0,Smin,gas;

    //读取输入
    scanf("%lf%lf%lf%lf%d",&D1,&C,&D,&fee[0],&N);

    for(i=1;i<=N;++i)scanf("%lf%lf",&dis[i],&fee[i]);//初始化数组
    dis[N+1]=D1;
    Cost=C*fee[0];//灌满油
    while(!flag){
        Smin=k+1;
        gas=k+1;
        if(k==0)for(i=0;i<=N;++i)if(dis[i]+C*D<dis[i+1])flag=1;//没找到下一个
        if(gas==N+1&&!flag){
            Cost-=(C-(dis[N+1]-dis[k])/D)*fee[k];
            break;
        }
        if(!flag){
            while(dis[gas]<=dis[k]+C*D){//找下一站
                if(fee[gas]<fee[k]){//当找到的值比k还小的时候
                    Smin=gas;
                    break;
                }
                Smin=fee[gas]<fee[Smin]? gas:Smin;//找到次小值
                if(gas<N)gas++;
                else break;
            }//找其中油费最低的
            rest=(dis[Smin]-dis[k])/D;
            if(fee[Smin]<fee[k])Cost+=C*(fee[Smin]-fee[k])+rest*fee[k];//比当前还低，退钱
            else Cost+=rest*fee[Smin];//补满
        }
        k=Smin;
    }
    if(flag)printf("No Solution");
    else printf("%.2lf",Cost);
    getchar();getchar();
    return 0;
}