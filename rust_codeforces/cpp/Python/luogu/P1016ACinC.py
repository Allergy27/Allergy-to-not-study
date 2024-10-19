"""
#灌满油
#include<stdio.h>
int main(){
    double D1,C,D,fee[9]={0},nowC=0,dis[9]={0},Cost=0;int i,j,k=0,N,flag=0,Smin,gas,rest;

    //读取输入
    scanf("%lf%lf%lf%lf%d",&D1,&C,&D,&fee[0],&N);

    for(i=1;i<=N;++i)scanf("%lf%lf",&dis[i],&fee[i]);//初始化数组
    dis[N+1]=D1;
    Cost=C*fee[0];//灌满油
    while(!flag){
        Smin=k+1;
        gas=k+1;
        if(gas==N+1){
            Cost-=(C-(dis[k+1]-dis[k])/D)*fee[k];
            break;
        }
        if(dis[k]+C*D<dis[k+1])flag=1;//没找到下一个
        if(!flag){
            while(dis[gas]<=dis[k]+C*D){//找下一站
                if(fee[gas]<fee[k]){
                    Smin=gas;
                    break;
                }
                if(fee[gas]<fee[Smin])Smin=gas;
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
"""
#读取输入部分
n=list(map(float,input().split()))#D1 C D2 P N
b=[[0,n[3]]]
for i in range(int(n[-1])):b.append(list(map(float,input().split())))
b.append([n[0],0])

flag=k=0
Cost=n[1]*b[0][1]

while flag:
    Smin=gas=k+1
    if gas==n[-1]:
        Cost-=(n[1]-(b[k+1][0]-b[k][0])/n[2])*b[k][1]#到终点站
        break
    if b[k][0]+n[1]*n[2]<b[k+1][0]:flag=1