#include<stdio.h>
#define maxN 31
char ans[maxN];int sum[31],rule[105],map[10];
void dfs(int);
int main(){
    unsigned long long SUM=1;
    scanf("%s",ans);
    int n,t,p,len,q;
    for(t=31;ans[t]==0;--t);
    len=t+1;//高精
    scanf("%d",&n);
    for(t=0;t<n;++t){
       scanf("%d %d",&p,&q);
       rule[p*10+q]=1;//对应关系
    }
    for(t=0;t<10;++t)dfs(t);
    for(t=0;t<len;++t)SUM*=map[ans[t]-'0']? map[ans[t]-'0']:1;
    printf("%d",SUM);
    getchar();getchar();
    return 0;
}
void dfs(int i){
    if(!map[i]){
        for(int Qwq=1;Qwq<10;++Qwq){
            if(rule[i*10+Qwq]){
                map[i]+=map[i]?1:2;
                dfs(Qwq);
            }
        }
    }
}