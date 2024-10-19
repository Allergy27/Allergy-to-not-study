a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=[b[i]+a[1] for i in range(len(b))]
d={}
for i in b:
    if i in d:d[i]+=1
    else:d[i]=1
ans=0
for i in c:
    if i in d:ans+=d[i]
print(ans)