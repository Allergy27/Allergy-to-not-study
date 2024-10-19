from bisect import bisect_left
from bisect import bisect_right
n,Q=map(int,input().split())
num=[]
for i in range(n):
    a=input()
    b=[]
    c=""
    for i in a:
        if i not in ('x','='):
            c+=i
        else:
            b.append(int(c))
            c=""
    b.append(int(c))
    d=(b[2]-b[1])//b[0]
    if d not in num:num.append(d)
num.sort()
for _ in range(Q):
    L,R=map(int,input().split())
    QWQ=bisect_left(num,L)
    QAQ=bisect_right(num,R)
    print(QAQ-QWQ)