#include<stdio.h>

int n,res;int map[9][9];
int dp[18][9][9];

int main(){
    int max(int,int,int,int);

    scanf("%d",&n);
    while(1){
        int x,y,val;
        scanf("%d%d%d",&x,&y,&val);
        if(x==0&&y==0&&val==0)break;
        map[x-1][y-1]=val;
    }
    dp[0][0][0]=map[0][0];
    for(int i=0;i<2*n;i++){
        for(int j=0;j<=i&&j<n;j++){
            for(int k=0;k<=i&&k<n;k++){
                
                if(i==0&&j==0&&k==0)continue;
                dp[i][j][k]=map[j][i-j]+map[k][i-k]+max(dp[i-1][j][k],dp[i-1][j-1][k-1],dp[i-1][j-1][k],dp[i-1][j][k-1]);
                if(j==k)dp[i][j][k]-=map[j][i-j];
            }
        }
    }
    res=dp[2*(n-1)][n-1][n-1];
    printf("%d",res);
    getchar();getchar();
    return 0;
}
int max(int a,int b,int c,int d){
    a=(a>b? a:b);
    c=(c>d? c:d);
    return (a>c? a:c);
}