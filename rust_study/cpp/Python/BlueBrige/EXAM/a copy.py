ans=""
for i in range(1,2024):
    ans+=str(i)
n=len(ans)
print(n**4)
res=0
for i in range(n-3):
    for j in range(i+1,n-2):
        for p in range(j+1,n-1):
            for q in range(p+1,n):
                if ans[i]+ans[j]+ans[p]+ans[q]=="2023":res+=1
print(res)
