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
        c[l]+=r
    else:
        print(sum(c[l-1:r+1])+b[r]-b[l-1])
"""
3 2
1 2 3
1 2 2
2 1 3

"""