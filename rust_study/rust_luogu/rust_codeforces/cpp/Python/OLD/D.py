n=int(input())-1
a=list(map(int,input().split()))
m=int(input())
for _ in range(m):
    i,j=0,n
    ans=0
    k=int(input())
    while i<=j:
        Mid=(i+j)//2
        if a[Mid]==k:
            break
        elif a[Mid]<k:
            i=Mid+1
        else:
            j=Mid-1
    if Mid>n-1:
        q=[a[Mid-1],a[Mid]]
    elif Mid<1:
        q=[a[Mid],a[Mid+1]]
    else:
        q=[a[Mid-1],a[Mid],a[Mid+1]]
    for i in range(1,len(q)):
        if abs(q[ans]-k)>abs(q[i]-k):
            ans=i
    print(q[ans])
"""
5
1 4 6 77 99
99
"""