#include<stdio.h>
char ans[102][102],res[102][102];
int main(){
    int N,D,i,j,all=0,max=0,flag=0;
    scanf("%d%d",&N,&D);
    for(i=0;i<N;++i)scanf("%s",ans[i]);
    for(i=0;i<N;++i)
        for(j=0;j<D;++j){
            res[j][i]=ans[i][j];
        }
    for(i=0;i<D;++i){
        for(j=0;j<N;++j){
            if(res[i][j]=='x'){
                flag=1;
                break;
            }
        }
        if(flag==0)++all;
        else{
            max=all>max? all:max;
            all=0;
        }
        flag=0;
    }
    printf("%d",max>all? max:all);   
    getchar();getchar();
    return 0;
}