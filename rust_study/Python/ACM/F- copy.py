n,d,p=map(int,input().split())
f=list(map(int,input().split()))
f.sort()
f=f[::-1]
Sum=sum(f)
ans=Sum
for i in range(0,n,d):
    for j in range(i,min(n,i+d)):
        Sum-=f[j]
    Sum+=p
    ans=min(ans,Sum)
print(ans)