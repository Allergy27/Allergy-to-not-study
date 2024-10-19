_ = int(input())
for t in range(_):
    n =  int(input())
    a= list(map(int,input().split()))
    ans=1
    f=0
    for i in a:
        if i==min(a) and f==0:
            ans*=(i+1)
            f=1
        else: ans*=i
    print(ans)
