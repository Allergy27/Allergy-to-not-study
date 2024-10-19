total,cost1,cost2=20,10,5
ans=total // cost1
num=0
for i in range(ans):
    tmp=0
    while total-i*cost1-tmp*cost2>0:
        tmp+=1
    num+=tmp+1
print(num)