n=int(input())
for i in range(n):
    a=list(map(int,input().split()))
    b=2*a[1]
    c=a[0]+a[2]
    if abs(b-c)%3==0:print(0)
    else:print(1)