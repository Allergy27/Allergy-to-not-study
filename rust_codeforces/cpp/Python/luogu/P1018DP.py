n,k=map(int,input().split())
ans=input()
dp=[[0 for j in range(n)]for i in range(k+1)]#dp[i][j]表示i个乘号，第j个数
for j in range(n):dp[0][j]=int(ans[:j+1])
for i in range(1,k+1):
    for j in range(i,n):
        for p in range(i-1,j):
            dp[i][j]=max(dp[i][j],dp[i-1][p]*int(str(dp[0][j])[p+1:]))
print(dp[k][n-1])