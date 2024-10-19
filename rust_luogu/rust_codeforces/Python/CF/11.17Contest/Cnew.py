def Count(t):
    i=0
    flag=True
    ans=0
    if max(t)<0 or len(t)==1:return max(t)
    while i<len(t):
        if t[i]<0 and flag:continue
        else flag=False
            ans+=t[i]
        if t[i]<0 and i+1<len(t):
            if min(t[i+1]+t[i],t[i-1]+t[i])>0:
                ans+=t[i+1]
                i+=1
            elif t[i+1]+t[i]<t[i]+t[i-1]:
                ans-=t[i]
                i+=1
            else:
                ans-=t[i]+t[i-1]
        elif t[i]<0 and i+1==len(t):ans-=t[i]
        i+=1
    return ans
_=int(input())
for __ in range(_):
    n=int(input())
    a=list(map(int,input().split()))
    b=[]
    c=[a[0]]
    for k in range(1,len(a)):pass