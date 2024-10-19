n,k=map(int,input().split())
a=list(map(int,input().split()))
b=a.copy()
ans=0
while ans<k:
    a=b.copy()
    c=1
    if min(a)>1:c=min(a)//2
    d=ans
    for i in range(len(b)):
        if b[i]>0:
            b[i]-=c
            ans+=c
for i in b:
    print(b,end=' ')