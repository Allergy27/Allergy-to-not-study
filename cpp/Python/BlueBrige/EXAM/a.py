ans=""
for i in range(1,2024):
    ans+=str(i)
dp1,dp2,dp3,dp4=0,0,0,0
for i in ans:
    if i=='2':dp1,dp3=dp1+1,dp3+dp2
    if i=='0':dp2+=dp1
    if i=='3':dp4+=dp3
print(dp4)
