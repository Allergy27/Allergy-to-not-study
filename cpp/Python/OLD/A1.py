n=int(input())
a=[]
for _ in range(n):a.append(int(input()))
a.sort()
b=a[::-1]
Amin=b[0]
Amax=a[0]
for i in range(1,len(b)):
    Amin=Amin*b[i]+1
c=1
for j in range(len(a)-1):
    a.append(a[0]*a[1]+1)
    if len(a)>1:
        del a[0]
        del a[0]
    a.sort()
print(a[-1]-Amin)