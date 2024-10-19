n=int(input())
for i in range(n):
    input()
    a=list(map(int,input().split()))
    b=[1 for i in range(len(a))]
    c=[]
    d=[]
    for j in range(len(a)):
        if a[j] not in c:c.append(a[j])
        elif a[j] not in d:#有重复且第一次出现
            b[j]=(len(d)+1)%3+1
            d.append(a[j])
    if len(d)<2:print(-1)
    else:
        for i in b:print(i,end=" ")
        print()