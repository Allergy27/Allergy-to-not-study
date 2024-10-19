#include<stdio.h>



int main(){
    int N,y1,y2,x=-1,y=-1,m=-1;int max(int,int,int,int);

    scanf("%d",&N);

    int Broad[N+1][N+1];
    int dp[N+N+1][N+1][N+1]; 

    for(int i=0;i<=N;++i)
        for(int j=0;j<=N;++j){
            Broad[i][j]=0;
            for(int k=0;k<=N*2;++k){
                dp[k][i][j]=0;
            }
        }
     while(scanf("%d%d%d",&y,&x,&m)&&(x!=0 || y!=0 || m!=0)){
        Broad[x][y]=m;//初始化有数据的棋盘
    }

    for(int k=1;k<=N*2;++k)
        for(int i=1;i<=(N<k? N:k);++i)
            for(int j=1;j<=(N<k? N:k);++j){
                dp[k][i][j]=max(dp[k - 1][i][j],dp[k - 1][i - 1][j],dp[k - 1][i][j - 1],dp[k - 1][i - 1][j - 1]) + Broad[k - i + 1][i] + Broad[k - j + 1][j];
                if(i == j) dp[k][i][j] -= Broad[k - i + 1][i];
            }
    dp[N*2][N][N]=max(dp[2*N - 1][N][N - 1],dp[2*N - 1][N - 1][N],dp[2*N - 1][N][N],dp[2*N - 1][N - 1][N - 1]);
    printf("%d\n",dp[2*N][N][N]);
    getchar();getchar();
    return 0;
}
int max(int a,int b,int c,int d){
    a=(a>b? a:b);
    c=(c>d? c:d);
    return (a>c? a:c);
}