from bisect import bisect_left as br
a=list(map(int,input().split()))
b=[a[0]]
c=[a[0]]
ans=0
for i in a[1:]:
    if i <= b[0]:
        b=[i]+b
    else:
        b[br(b,i)-1]=i
    if i > max(c):
        c.append(i)
    else:
        c[br(c,i)]=i
print(len(b))
print(len(c))