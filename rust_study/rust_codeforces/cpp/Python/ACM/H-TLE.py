t=int(input())
def Find(List,Time,all,Goal,p,q):#Time耗时,all当前值
    if all==Goal or p>q:return Time
    a=Find(List,Time+1,all-List[p],Goal,p+1,q)
    b=Find(List,Time+1,all-List[q],Goal,p,q-1)
    return min(a,b)

for _ in range(t):
    n,s=map(int,input().split())
    a=list(map(int,input().split()))
    Sum=sum(a)
    if Sum<s:print(-1)
    elif Sum==s:print(0)
    else:print(Find(a,0,Sum,s,0,n-1))
