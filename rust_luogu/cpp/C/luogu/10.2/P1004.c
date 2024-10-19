#include <stdio.h>

typedef struct block{
    int val;
    int flag;
} bk;


int main(){
    int N,y=-1,x=-1,n=-1;int ans;

    scanf("%d",&N);
    bk broad1[N+1][N+1];
    bk broad2[N+1][N+1];
    for(int i=0;i<N+1;++i){
        for(int j=0;j<N+1;++j){
            broad1[i][j].val=0;broad2[i][j].val=0;
            broad1[i][j].flag=0;
        }
    }
    while(scanf("%d%d%d",&y,&x,&n)&&(x!=0 || y!=0 || n!=0)){
        broad1[y+1][x+1].val=n;//初始化有数据的棋盘
        broad2[y+1][x+1].val=n;
    }
    for(int i=1;i<N+1;++i){
        for(int j=1;j<N+1;++j){
            if(broad1[i-1][j].val>broad1[i][j-1].val){
                broad1[i][j].val+=broad1[i-1][j].val;
                broad1[i-1][j].flag=1;
                broad1[i][j-1].flag=0;
            }
            else {
                broad1[i][j].val+=broad1[i][j-1].val;
                broad1[i][j-1].flag=1;
                broad1[i-1][j].flag=0;
            }
        }
    }
    ans += broad1[N][N].val;
    for(int i=1;i<N+1;++i){
        for(int j=1;j<N+1;++j){
            if(broad1[i-1][j].flag==1)broad2[i-1][j].val=0;
            if(broad1[i][j-1].flag==1)broad2[i][j-1].val=0;
            if(broad2[i-1][j].val>broad2[i][j-1].val)broad2[i][j].val+=broad2[i-1][j].val;
            else broad2[i][j].val+=broad2[i][j-1].val;
        }
    }
    printf("%d",ans+broad2[N][N].val);
    getchar();getchar();
    return 0;
}
//f[k][i][j]=max(f[k−1][i][j],f[k−1][i−1][j]f[k−1][i][j−1]f[k−1][i−1][j−1])+[(i==j)?map[k−i+1][i]:map[k−i+1][i]+map[k−j+1][j]]