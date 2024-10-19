n=int(input())
for i in range(n):
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    c=list(map(int,input().split()))
    b.append(1)
    b.sort()
    c.sort()
    ans=0
    L=a[0]
    j=0
    while j < L:
        if b[j]>=c[j]:
            c=c[1:]
            b=b[:L-1]
            ans+=1
            L-=1
            j-=1
        j+=1
    print(ans)