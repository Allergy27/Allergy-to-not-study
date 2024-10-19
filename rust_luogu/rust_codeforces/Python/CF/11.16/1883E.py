from math import log2
n=int(input())
for i in range(n):
    a=int(input())
    b=list(map(int,input().split()))
    ans=0
    mul=0
    for j in range(1,len(b)):
        if b[j]>=b[j-1]:
            if b[j]>b[j-1]<<mul:mul=0
            else:
                t=0
                while b[j-1]<<t<=b[j]:t+=1
                mul-=t-1
        else:
            t=0
            while b[j]<<t<b[j-1]:t+=1
            mul+=t
        ans+=mul
    print("\t",ans)