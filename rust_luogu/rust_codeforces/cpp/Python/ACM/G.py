T=int(input())
for _ in range(T):
    input()
    C={}
    a=list(map(int,input().split()))
    """
    b=sorted(a)
    for i in range(len(b)):
        C[b[i]]=i
    """
    d={}
    e=[]
    ans=0
    for i in a:
        if i+1 not in d:
            d[i]=1
        else:
            d[i+1]-=1
            d[i]=1
        e.append(i)
    for i in e:
        ans+=d[i]
    print(ans)