a=list(map(int,input().split()))
all=[]
ans=0
for i in range(a[0]):
    all.append(list(map(int,input().split())))
for j in range(a[0]):
    dp=[[0 for _ in range(a[1]+2)] for _ in range(a[1]+2)]  
    for L in range(a[1]+1):
        for i in range(1,a[1]+1-L):
            dp[i][i+L]=max(2*dp[i+1][i+L]+2*all[j][i-1],2*dp[i][i+L-1]+2*all[j][i+L-1])
    ans+=dp[1][a[1]]
print(ans)