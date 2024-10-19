n=int(input())
a=list(map(int,input().split()))
b=[]
for i in range(1,n+1):
    c=a.index(i)
    if i != c :b.append([i,c+1])
    a[i-1],a[c]=a[c],a[i-1]
print(len(b))
for [x,y] in b:
    print(x,y)