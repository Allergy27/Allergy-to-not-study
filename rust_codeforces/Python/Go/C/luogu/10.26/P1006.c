#include<stdio.h>

int m,n,k,i,j,map[51][51],dp[102][51][51];

int main(){
    int max(int,int,int,int);
    scanf("%d%d",&m,&n);
    for(i=0;i<m;++i)
        for(j=0;j<n;++j)
            scanf("%d",&map[i][j]);//读取数据
    for(k=0 ; k<m+n ; ++k)  
        for(i=0 ; i<m && i<=k ; ++i)
            for(j=0 ; j<m && j<=k ; ++j){
                if(k==0 && i==0 && j==0)continue;//最开始的情况，排除在外
                dp[k][i][j]=map[i][k-i]+map[j][k-j]+max(dp[k-1][i][j],dp[k-1][i-1][j-1],dp[k-1][i-1][j],dp[k-1][i][j-1]);
                //dp表，用于求最大值
                if(i==j)dp[k][i][j]-=map[i][k-i];//两次一起取，如果都取了就删去一个
            }
    printf("%d",dp[m+n-1][m-1][m-1]);
    getchar();getchar();
    return 0;
}
int max(int a,int b,int c,int d){
    a=(a>b? a:b);
    c=(c>d? c:d);
    return (a>c? a:c);
}