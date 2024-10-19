n=int(input())
for i in range(n):
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    for j in range(len(b)):
        b[j]%=a[1]
    if 0 not in b and a[1]!=4:
        print(a[1]-max(b))
    elif  0 not in b and a[1]==4:
        print(min(a[1]-max(b),max(0,2-b.count(2))))
    else:
        print(0)