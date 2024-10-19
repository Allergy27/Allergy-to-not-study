n,q=map(int,input().split())
b=[0]
a=list(map(int,input().split()))
Sum=0
for i in a:
    Sum+=i
    b.append(Sum)
c=[0 for i in range(len(b))]
for k in range(q):
    num,l,r=map(int,input().split())
    if num%2==1:
        d=[i+r for i in b[r:]]
        b=b[:r]+d
    else:
        print(b[r]-b[l-1])