c=int(input()[0])
a=list(map(int,input().split()))
b=list(map(int,input().split()))
d=[0 for i in range(c)]
e=[0 for i in range(c)]

flag=True
for i in range(len(b)):
    if a[i]==b[i]:
        flag=False
        break
    if d[b[i]-1]==d[a[i]-1] and not e[b[i]-1]:
        d[b[i]-1]=[1,0][d[a[i]-1]]
        e[b[i]-1]=1
    elif d[b[i]-1]==d[a[i]-1] and e[b[i]-1]:
        flag=False
        break
if flag:print("Yes")
else:print("No")