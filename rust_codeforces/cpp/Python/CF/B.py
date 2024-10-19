n=int(input())
for i in range(n):
    a=list(map(int,input().split()))
    b=input()
    c={}
    d=[]
    t=0
    for j in b:
        if j not in c:
            c[j]=1
            d.append(j)
        else:
            c[j]+=1
    for j in d:
        if c[j]%2==1:t+=1
    if t-a[1] < 2:
        print("YES")
    else:
        print("NO")