n=int(input())
for i in range(n):
    n,m=map(int,input().split())
    a=min(n,m)
    b=max(n,m)
    if a==b==1:print(0)
    else:print(b-2+2*a)