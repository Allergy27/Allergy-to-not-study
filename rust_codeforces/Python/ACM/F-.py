from bisect import bisect_left as br
n,d,p=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
b=br(a,p/d)#有多少是少于车票单价的
#接下来我们分买票和直接买
"""
5 4 1
1 1 1 2 1
"""
#买几次票
numt=(n-b)//d
if n-numt*d>0:numt+=1
fee=sum(a)
if n-numt*d<=0:
    fee=min(numt*p,fee)
else:#有少于单价的
    fee=min(sum(a[:n-numt*d])+numt*p,fee)
    numt-=1
    fee=min(sum(a[:n-numt*d])+numt*p,fee)
print(fee)
