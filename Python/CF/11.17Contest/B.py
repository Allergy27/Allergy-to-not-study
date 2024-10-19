_=int(input())
for __ in range(_):
    n=int(input())
    a=list(map(int,input().split()))
    ans=0
    for i in range(1,1+int(n//2)):
        if n%i!=0 and i!=1:continue
        ansa=sum(a[:i])
        ansi=sum(a[:i])
        for j in range(i,n,i):
            ansa=max(ansa,sum(a[j:j+i]))
            ansi=min(ansi,sum(a[j:j+i]))
        ans=max(ansa-ansi,ans)
    print(ans)