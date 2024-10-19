n,k=map(int,input().split())
a=list(map(int,input().split()))
i=len(a)-1
ans=0
while n-a[i]<0 and i>0:i-=1
while n-a[i]>=0:
    n-=a[i]
    ans+=a[i]#高桥拿好了
    while n-a[i]<0 and i>0:i-=1
    n-=a[i]
    while n-a[i]<0 and i>0:i-=1
print(ans)