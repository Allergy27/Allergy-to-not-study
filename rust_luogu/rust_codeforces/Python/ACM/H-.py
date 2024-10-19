t=int(input())
for _ in range(t):
    n,s=map(int,input().split())
    a=list(map(int,input().split()))
    Sum=sum(a)
    if Sum<s:print(-1)
    elif Sum==s:print(0)
    else:
        L=0
        R=n-1
        Lnext=0
        Rnext=0
        while L<R:
            while a[L+Lnext]!=1:Lnext+=1
            while a[R-Rnext]!=1:Rnext+=1
            if Rnext<Lnext:
                R-=Rnext+1
                Rnext=0
            else:
                L+=Lnext+1
                Lnext=0
            Sum-=1
            if Sum==s:break
        print(n-R+L-1)
"""
1
8 3
1 0 1 0 0 1 1 0
"""