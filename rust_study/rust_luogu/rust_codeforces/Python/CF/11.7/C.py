N=int(input())
for i in range(N):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    b=0
    r=n-1
    flag=False
    while b<=n:
        b+=1
        if a[r]>n:
            flag=True
            break
        r=(r-a[r])%n
    if flag and k>=b:print("No")
    else:print("Yes")
