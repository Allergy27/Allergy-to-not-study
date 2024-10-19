t,k=map(int,input().split())
dp=[i for i in range(1,k+1)]
mod=10**9+7
for i in range(k,100001):
    dp.append((dp[i-1]+dp[i-k]+1)%mod)
for i in range(t):
    a,b=map(int,input().split())
    print((dp[b]-dp[a-1])%mod)
"""
1859 48096
96000 96192
75634 80941
27808 89615
58867 93494
95515 99613
68307 69216
87597 99003
"""