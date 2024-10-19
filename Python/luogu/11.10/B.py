a,b,c,d,M=map(int,input().split())
ans=c*5-20*b
if c*5>M:
    ans+=40*d
else:
    ans+=20*d
if ans>0:print(ans)
else:print(0)