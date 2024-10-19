_=int(input())
for __ in range(_):
    n=int(input())
    a=list(map(int,input().split()))
    b=[[0,1][i%2] for i in a]
    c=[]
    flag=b[0]
    MaxNum=[a[0]]
    for i in range(1,n):
        if b[i]==b[i-1]:
            MaxNum.append(a[i])
        else:
            c.append(max(MaxNum))
            MaxNum=[a[i]]
    if len(a)==1 or len(MaxNum)>1 or max(MaxNum) != c[-1]:#这个判断有点草率，不过就优化
        c.append(max(MaxNum))
    if len(c)==1 or max(c)<0:print(max(c))
    else:
        cur=sum(c)
        pre=0
        for i in range(len(c)):
            if c[i]>0 and pre==0:pre=1
            if c[i]<0 and (pre==0 or i+1==len(c)):
                cur-=c[i]
                continue
            if c[i] < 0:
                if min(c[i-1]+c[i],c[i+1]+c[i])>0:
                    continue
                else:
                    if min(c[i-1],c[i+1])==c[i+1]:i+=1
                    cur-=min(c[i-1]+c[i],c[i+1]+c[i])
        print(cur)